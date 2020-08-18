#!/usr/bin/perl
use strict;
use warnings;
use diagnostics;

# This works for IMGUI 1.60 and does not get all functions
#
# to use ./generate_imgui_bindings.pl <../imgui/imgui.h >imgui_iterator.inl
# and define macros properly as in example imgui_lua_bindings.cpp
#
# check imgui_iterator for explanations of why some functions are not supported yet

require "./parse_blocks.pl";

sub generateNamespaceImgui {
  my ($imguiCodeBlock) = @_;

  my $lineCaptureRegex = qr" *(IMGUI_API) *((const char\*)|([^ ]+)) *([^\(]+)\(([^\;]*)\);";
  my $doEndStackOptions = 1;
  my $terminator = "} \/\/ namespace ImGui";
  my $callPrefix = "";
  my $functionSuffix = "";

#define bannedNames with keys of functions to exclude them
# EXAMPLE:
  my %bannedNames = (
    "NewFrame" => "banned",
    "Shutdown" => "banned" );
#
# This is only useful for ENABLE_IM_LUA_END_STACK
# We hold a list of differnet 'things' that can be pushed to the stack
# i.e. Group for BeginGroup
# It usually works like this BeginBlah EndBlah

# We have to redefine stuff when it doesn't work so cleanly
  my %beginN = (
    "TreeNode" => "Tree",
    "TreePush" => "Tree",
    "PushStyleVar" => "StyleVar"
    );
  my %changeN = (
    "Tree" => "TreePop",
    "StyleVar"=> "PopStyleVar"
    );
  my %endN = (
    "TreePop" => "Tree",
    "PopStyleVar" => "StyleVar"
    );
  my %endOverride = (
    "PopupModal" => "Popup",
    "PopupContextItem" => "Popup",
    "PopupContextWindow" => "Popup",
    "PopupContextVoid" => "Popup" );

  generateImguiGeneric(
    $lineCaptureRegex,
    $doEndStackOptions,
    $terminator,
    $callPrefix,
    $functionSuffix,
    \%bannedNames,
    \%beginN,
    \%changeN,
    \%endN,
    \%endOverride,
    $imguiCodeBlock)
}

sub generateDrawListFunctions {
  my ($imguiCodeBlock) = @_;

  my $lineCaptureRegex = qr" *(IMGUI_API|inline) *((const char\*)|([^ ]+)) *([^\(]+)\(([^\;]*)\);";
  my $doEndStackOptions = 0;
  my $terminator = 0;
  my $callPrefix = "DRAW_LIST_";
  my $functionSuffix = "_DRAW_LIST";

#define bannedNames with keys of functions to exclude them
# EXAMPLE:
  my %bannedNames = (
    "_ResetForNewFrame"=>"banned",
    "_ClearFreeMemory"=>"banned",
    "_PopUnusedDrawCmd"=>"banned",
    "_OnChangedClipRect"=>"banned",
    "_OnChangedTextureID"=>"banned",
    "_OnChangedVtxOffset"=>"banned",
    
   );
#
# This is only useful for ENABLE_IM_LUA_END_STACK
# We hold a list of differnet 'things' that can be pushed to the stack
# i.e. Group for BeginGroup
# It usually works like this BeginBlah EndBlah

# We have to redefine stuff when it doesn't work so cleanly
  my %beginN = (
    );
  my %changeN = (
    );
  my %endN = (
    );
  my %endOverride = (
     );


  generateImguiGeneric(
    $lineCaptureRegex,
    $doEndStackOptions,
    $terminator,
    $callPrefix,
    $functionSuffix,
    \%bannedNames,
    \%beginN,
    \%changeN,
    \%endN,
    \%endOverride,
    $imguiCodeBlock)
}

my @enum_types;
my $enum_match;

sub generateImguiGeneric {
  my $lineCaptureRegex = shift;
  my $doEndStackOptions = shift;
  my $terminator = shift;
  my $callPrefix = shift;
  my $functionSuffix = shift;

#define bannedNames with keys of functions to exclude them
# EXAMPLE:
  my $bannedNamesRef = shift;
  my %bannedNames = %{$bannedNamesRef};
#
# This is only useful for ENABLE_IM_LUA_END_STACK
# We hold a list of differnet 'things' that can be pushed to the stack
# i.e. Group for BeginGroup
# It usually works like this BeginBlah EndBlah

# We have to redefine stuff when it doesn't work so cleanly
  my $beginNRef = shift;
  my %beginN = %{$beginNRef};
  my $changeNRef = shift;
  my %changeN = %{$changeNRef};
  my $endNRef = shift;
  my %endN = %{$endNRef};
  my $endOverrideRef = shift;
  my %endOverride = %{$endOverrideRef};

  my ($imguiCodeBlock) = @_;


  my $numSupported = 0;
  my $numUnsupported = 0;
  my $line;
  my %funcNames;
  my %endTypeToInt;
  my @endTypes;
  my @functionsAlreadyAdded;
  foreach $line (split /\n/, $imguiCodeBlock) {
    #replace ImVec2(x, y) with ImVec2 x, y so it's easier for regex (and ImVec4)
    $line =~ s/ImVec2\(([^,]*),([^\)]*)\)/ImVec2 $1 $2/g;
    $line =~ s/ImVec4\(([^,]*),([^\)]*),([^\)]*),([^\)]*)\)/ImVec4 $1 $2 $3 $4/g;

    #delete this so it's eaiser for regexes
    $line =~ s/ IM_PRINTFARGS\(.\);/;/g;
    if ($line =~ m/$lineCaptureRegex/) {
      print "//" . $line . "\n";
      # this will be set to 0 if something is not supported yet
      my $shouldPrint = 1;
      my @args = split(',', $6);
      # things to do before calling real c++ function
      my @before;
      # arguments to real c++ function
      my @funcArgs;
      # things to do after callign real c++ function
      my @after;
      
      # after after, for allowing return value reordering
      my @lastRet;
      
      # real c++ function name
      my $funcName = $5;

	  #say STDERR "Parsing function: " . $funcName;
	  if (grep(/^$funcName$/, @functionsAlreadyAdded)) {
		  #say STDERR $funcName;
	  }
	  push @functionsAlreadyAdded, $funcName;
	  
      if (defined($bannedNames{$funcName})) {
        print "//Not allowed to use this function\n";
        $shouldPrint = 0;
      }
      # c++ type of return value
      my $retType = $2;
      # macro used for calling function
      my $callMacro;
      # if it has a return value (yes I know this is not the cleanest code)
      my $hasRet = 1;
      

      if ($retType =~ /^void$/) {
        $callMacro = "${callPrefix}CALL_FUNCTION_NO_RET";
        $hasRet = 0;
      } elsif ($retType =~ /^const char\*$/) {
        $callMacro = "${callPrefix}CALL_FUNCTION";
        push(@funcArgs, "const char*");
        push(@after, "PUSH_STRING(ret)");
        push(@lastRet, "PUSH_LAST_STRING(ret)");
      } elsif ($retType =~ /^bool$/) {
        $callMacro = "${callPrefix}CALL_FUNCTION";
        push(@funcArgs, "bool");
        push(@after, "PUSH_BOOL(ret)");
        push(@lastRet, "PUSH_LAST_BOOL(ret)");
      } elsif ($retType =~ /^(int|float|double)$/) {
        $callMacro = "${callPrefix}CALL_FUNCTION";
        push(@funcArgs, "float");
        push(@after, "PUSH_NUMBER(ret)");
        push(@lastRet, "PUSH_LAST_NUMBER(ret)");
      } elsif ($retType =~ /^ImVec2$/) {
        $callMacro = "${callPrefix}CALL_FUNCTION";
        push(@funcArgs, "ImVec2");
        push(@after, "PUSH_NUMBER(ret.x)");
        push(@after, "PUSH_NUMBER(ret.y)");
        push(@lastRet, "PUSH_LAST_NUMBER(ret.x)");
        push(@lastRet, "PUSH_LAST_NUMBER(ret.y)");
      } elsif ($retType =~ /^(unsigned int|ImGuiID|ImU32)$/) {
        $callMacro = "${callPrefix}CALL_FUNCTION";
        push(@funcArgs, "unsigned int");
        push(@after, "PUSH_NUMBER(ret)");
        push(@lastRet, "PUSH_LAST_NUMBER(ret)");
      } else {
        print "// Unsupported return type $retType\n";
        $shouldPrint = 0;
      }
      for (my $i = 0; $i < @args; $i++) {
        # bool * x = NULL or bool * x
        if ($args[$i] =~ m/^ *bool *\* *([^ =\[]*)( = NULL|) *$/) {
          my $name = $1;
          if ($2 =~ m/^ = NULL$/) {
            push(@before, "OPTIONAL_BOOL_POINTER_ARG($name)");
          } else {
            push(@before, "BOOL_POINTER_ARG($name)");
          }
          push(@funcArgs, $name);
          push(@after, "END_BOOL_POINTER($name)");
        # float * x
        } elsif ($args[$i] =~ m/^ *float *\* *([^ =\[]*)$/) {
          my $name = $1;
          push(@before, "FLOAT_POINTER_ARG($name)");
          push(@funcArgs, $name);
          push(@after, "END_FLOAT_POINTER($name)");
        #float a or float a = number
        } elsif ($args[$i] =~ m/^ *float *([^ =\[]*)( *= *[^ ]*|)$/) {
          my $name = $1;
          if ($2 =~ m/^ *= *([^ ]*)$/) {
            push(@before, "OPTIONAL_NUMBER_ARG($name, $1)");
          } else {
            push(@before, "NUMBER_ARG($name)");
          }
          push(@funcArgs, $name);
        
        #const float *
        } elsif ($args[$i] =~ m/^ *const float\* *([^ =\[]*)/){
          my $name = $1;
          push(@before, "FLOAT_ARRAY_ARG($name)");
          push(@funcArgs, $name);
        #float v[n]
        } elsif ($args[$i] =~ m/^ *float *([^ =\[]*)\[([0-9]*)]/) {
          my $name = $1;
          
          push(@before, "FLOAT_ARRAY$2_ARG($name)");
          push(@funcArgs, $name);
          push(@after, "END_FLOAT_ARRAY$2($name)");
        # const char* a or const char* a = NULL or "blah"
        } elsif ($args[$i] =~ m/^ *const char\* *([^ =\[]*)( *= *(NULL|".*")|) *$/) {
          my $name = $1;
          if ($2 =~ m/^ *= *(NULL|".*")$/) {
            push(@before, "OPTIONAL_LABEL_ARG($name, $1)");
          } else {
            push(@before, "LABEL_ARG($name)");
          }
          push(@funcArgs, $name);
        # char*
        } elsif ($args[$i] =~ m/^ *char *\* *([^ =\[]*)$/) {
          my $name = $1;
          push(@before, "LABEL_POINTER_ARG($name)");
          push(@funcArgs, $name);
          push(@after, "END_LABEL_POINTER($name)");
        
        # const char* const x[]
        } elsif ($args[$i] =~ m/^ *const char\* *const *([^ =\[]*)\[] *$/) {
          my $name = $1;
          push(@before, "LABEL_ARRAY_ARG($name)");
          push(@funcArgs, $name);
        
        #const ImVec2& with default or not
        } elsif ($args[$i] =~ m/^ *const ImVec2& ([^ ]*)( *= *ImVec2 [^ ]* *[^ ]*|) *$/) {
          my $name = $1;
          
          if ($2 =~ m/^ *= ImVec2 ([^ ]*) *([^ ]*)$/) {
            push(@before, "OPTIONAL_IM_VEC_2_ARG($name, $1, $2)");
          } else {
            push(@before, "IM_VEC_2_ARG($name)");
          }
          push(@funcArgs, $name);
        # ImVec2 with default or not
        } elsif ($args[$i] =~ m/^ *ImVec2 ([^ ]*)( *= *ImVec2 [^ ]* *[^ ]*|) *$/) {
          my $name = $1;
          if ($2 =~ m/^ *= ImVec2 ([^ ]*) *([^ ]*)$/) {
            push(@before, "OPTIONAL_IM_VEC_2_ARG($name, $1, $2)");
          } else {
            push(@before, "IM_VEC_2_ARG($name)");
          }
          push(@funcArgs, $name);
        # const ImVec2 *
        } elsif ($args[$i] =~ m/^ *const ImVec2 *\* *([^ =\[]*)$/) {
          my $name = $1;
          push(@before, "IM_VEC_2_ARRAY_ARG($name)");
          push(@funcArgs, $name);
          
        #const ImVec4& with default or not
        } elsif ($args[$i] =~ m/^ *const ImVec4& ([^ ]*) *(= * ImVec4 [^ ]* [^ ]* [^ ]* [^ ]*|) *$/) {
          my $name = $1;
          if ($2 =~ m/^= * ImVec4 ([^ ]*) ([^ ]*) ([^ ]*) ([^ ]*)$/) {
            push(@before, "OPTIONAL_IM_VEC_4_ARG($name, $1, $2, $3, $4)");
          } else {
            push(@before, "IM_VEC_4_ARG($name)");
          }
          push(@funcArgs, $name);
        # Enums
        } elsif ($args[$i] =~ m/^ *($enum_match) *([^ =,\[]*]*)( *= *.*|) *$/) {
         my $name = $2;
          if ($3 =~ m/^ *= *([^ ,]*)$/) {
            push(@before, "OPTIONAL_ENUM_ARG($name, $1)");
          } else {
            push(@before, "ENUM_ARG($name)");
          }
          push(@funcArgs, $name);
        #int with default value or not
        } elsif ($args[$i] =~ m/^ *int ([^ =\[]*)( = [^ ]*|) *$/) {
          my $name = $1;
          if ($2 =~ m/^ = ([^ ]*)$/) {
            push(@before, "OPTIONAL_INT_ARG($name, $1)");
          } else {
            push(@before, "INT_ARG($name)");
          }
          push(@funcArgs, $name);
        #unsigned int with default value or not
        } elsif ($args[$i] =~ m/^ *(unsigned +int|ImGuiID|ImU32|) ([^ =\[]*)( *= *[^ ]*|) *$/) {
          my $name = $2;
          if ($3 =~ m/^ *= *([^ ]*)$/) {
            push(@before, "OPTIONAL_UINT_ARG($name, $1)");
          } else {
            push(@before, "UINT_ARG($name)");
          }
          push(@funcArgs, $name);
        
        #int v[n]
        } elsif ($args[$i] =~ m/^ *int *([^ =\[]*)\[([0-9]*)]/) {
          my $name = $1;
          
          push(@before, "INT_ARRAY$2_ARG($name)");
          push(@funcArgs, $name);
          push(@after, "END_INT_ARRAY$2($name)");

        #ImTextureID or const ImTextureID&
        # const ImTextureID& is the same thing as var
        # as lua is concerned
        } elsif ($args[$i] =~ m/^ *(ImTextureID|const ImTextureID&) ([^ =\[]*) *$/) {
          my $name = $2;
          push(@before, "TEXTURE_ARG($name)");
          push(@funcArgs, $name);
        # bool with default value or not
        } elsif ($args[$i] =~ m/^ *bool ([^ =\[]*)( *= *true| *= *false|) *$/) {
          my $name = $1;
          if ($2 =~ m/^ *= *([^ ]*)$/) {
            push(@before, "OPTIONAL_BOOL_ARG($name, $1)");
          } else {
            push(@before, "BOOL_ARG($name)");
          }
          push(@funcArgs, $name);
        # int * x
        } elsif ($args[$i] =~ m/^ *int *\* *([^ =\[]*)$/) {
          my $name = $1;
          push(@before, "INT_POINTER_ARG($name)");
          push(@funcArgs, $name);
          push(@after, "END_INT_POINTER($name)");
        # unsigned int * x
        } elsif ($args[$i] =~ m/^ *unsigned +int *\* *([^ =\[]*)$/) {
          my $name = $1;
          push(@before, "UINT_POINTER_ARG($name)");
          push(@funcArgs, $name);
          push(@after, "END_UINT_POINTER($name)");
          
        # Unsupported types with a default value
        } elsif ($args[$i] =~ m/^ *([^ ]*) *([^ =\[]*]*) *= *([^ \.]*)$/) {
          my $name = $2;
          push(@before, "DEFAULT_ARG($1, $name, $3)");
        # we don't support variadic functions yet but we let you use it without extra variables
        } elsif ($args[$i] =~ m/^ *\.\.\. *$/) {
          print "// Variadic functions aren't suppported but here it is anyway\n";
        } else {
          print "// Unsupported arg type " . $args[$i] . "\n";
          $shouldPrint = 0;
        }
      }
      if ($shouldPrint != 0) {
        my $luaFunc = $funcName;
        # Stupid way of implementing overriding
        if (not exists $funcNames{$luaFunc}) {
            $funcNames{$luaFunc} = 0;
        }
        
        $funcNames{$luaFunc} += 1;
        
        my $suffix = "";
        if ($funcNames{$luaFunc} > 1) {
            my $num = $funcNames{$luaFunc};
            $suffix = "_$num";
        }
        
		
        print "IMGUI_FUNCTION${functionSuffix}($luaFunc$suffix)\n";
        for (my $i = 0; $i < @before; $i++) {
          print $before[$i] . "\n";
        }

        print $callMacro . "($funcName";
        for (my $i = 0; $i < @funcArgs; $i++) {
          print ", " . $funcArgs[$i];
        }
        print ")\n";

        #for begin and end stack stuff
        if ($funcName =~ m/^Begin(.*)$/ || defined($beginN{$funcName})) {
          my $curEndType;
          if (defined($beginN{$funcName})) {
            $curEndType = $beginN{$funcName};
          } else {
            $curEndType = $1;
          }
          if (defined($endOverride{$curEndType})) {
            $curEndType = $endOverride{$curEndType};
          }
          if (!defined($endTypeToInt{$curEndType})) {
            $endTypeToInt{$curEndType} = scalar(@endTypes);
            push(@endTypes, $curEndType);
          }
          my $curEndTypeInt = $endTypeToInt{$curEndType};
          if ($hasRet) {
            print "IF_RET_ADD_END_STACK($curEndTypeInt)\n";
          } else {
            print "ADD_END_STACK($curEndTypeInt)\n";
          }
        } elsif ($funcName =~ m/^End(.*)$/ || defined($endN{$funcName})) {
          my $curEndType;
          if (defined($endN{$funcName})) {
            $curEndType = $endN{$funcName};
          } else {
            $curEndType = $1;
          }
          if (defined($endOverride{$curEndType})) {
            $curEndType = $endOverride{$curEndType};
          }
          if (!defined($endTypeToInt{$curEndType})) {
            $endTypeToInt{$curEndType} = scalar(@endTypes);
            push(@endTypes, $curEndType);
          }
          my $curEndTypeInt = $endTypeToInt{$curEndType};
          print "POP_END_STACK($curEndTypeInt)\n"
        }

        for (my $i = 0; $i < @after; $i++) {
          print $after[$i] . "\n";
        }
        
        for (my $i = 0; $i < @lastRet; $i++) {
          print $lastRet[$i] . "\n";
        }
        
        print "END_IMGUI_FUNC\n\n";
        $numSupported += 1;
      } else {
        $numUnsupported += 1;
      }
    } elsif ($terminator) {
        if ($line =~ m/^${terminator}$/) {
            last;
        }
    }
  }
#for end stack stuff
  if ($doEndStackOptions)
  {
      print "END_STACK_START\n";
      for (my $i = 0; $i < @endTypes; $i++) {
          my $endFunc;
          if (defined($changeN{$endTypes[$i]})) {
              $endFunc = $changeN{$endTypes[$i]};
          } else {
              $endFunc = "End" . $endTypes[$i];
          }
          print "END_STACK_OPTION($i, " . $endFunc .")\n";
      }
      print "END_STACK_END\n";
  }

#debug info
  print STDERR "Supported: $numSupported Unsupported: $numUnsupported\n";

}

sub generateEnums {
  my $enumName = shift;
  
  push(@enum_types, $enumName);
  
  my ($imguiCodeBlock) = @_;

  my $lineCaptureRegex = qr"^ *((?:ImGui|ImDraw)[^, _]+)_([a-zA-Z0-9]+)\b";

  my $line;
  foreach $line (split /\n/, $imguiCodeBlock) {
    if ($line =~ m/$lineCaptureRegex/) {
      die "Malformed enum at $enumName" unless ($1 eq $enumName);

      print "//" . $line . "\n";
      print "MAKE_ENUM($1_$2)\n";
    }
  }
}

my ($blocksref, $blocknamesref) = parse_blocks();

my @blocks = @$blocksref;
my @blocknames = @$blocknamesref;

open(FH, '>', "imgui_enum.h") or die $!;
select(FH);

for (my $i=0; $i < scalar @blocks; $i++) {

  if ($blocknames[$i] =~ m/enum ((ImGui|ImDraw).*)_\n/) {
    print "//" . $blocknames[$i] . "\n";
    generateEnums($1, $blocks[$i]);
    print "\n";
  }
}

close(FH);

$enum_match = join "|", @enum_types;
print STDERR "$enum_match\n";

# @spaderthomas 3/1/2020: ImGui also puts its deprecated functions in namespace ImGui,
# so we'll end up parsing a couple functions twice and causing compiler errors.
#
# This flag just means that we've parsed the main one, so don't parse the next one. If ImGui
# splits up its header to multiple instances of namespace ImGui, this would break.
my $alreadyParsedMainImguiNamespace = 0;

open(FH, '>', "imgui_iterator.h") or die $1;
select(FH);

for (my $i=0; $i < scalar @blocks; $i++) {
  if (($blocknames[$i] eq "namespace ImGui\n") and not $alreadyParsedMainImguiNamespace) {
	$alreadyParsedMainImguiNamespace = 1;
    print "//" . $blocknames[$i] . "\n";
    print STDERR "ImGui\n";
    generateNamespaceImgui($blocks[$i]);
  }
}

close(FH);

open(FH, '>', "imgui_drawlist_iterator.h") or die $!;
select(FH);

for (my $i=0; $i < scalar @blocks; $i++) {
  if ($blocknames[$i] eq "struct ImDrawList\n") {
    print "//" . $blocknames[$i] . "\n";
    print STDERR "Draw List\n";
    generateDrawListFunctions($blocks[$i]);
  }
}

close(FH);


