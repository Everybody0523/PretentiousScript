// Basically booleans
const int MATCH = 0;

//Primitives
const char PRIMITIVES [2][32];
PRIMITIVES[0] = "MEMBER_OF_Z";
PRIMITIVES[1] = "Character";

const char CONDITIONALS[3][32];
CONDITIONALS[0] = "Suppose"; //If
CONDITIONALS[1] = "Alternatively"; //Else If
CONDITIONALS[2] = "Otherwise"; //Else

//COMMENT
const char * COMMENT0 = "Contemplation:"
const char * COMMENT1 = "contemplation:"

//Regular Expressions
const char * VALIDNAMES = "[[:alpha:]+[:print:]*]";
//A valid name for a variable or function begins with an alphanumeric
// character, then a series of printable characters. Something like 1a, or -a
// is not a valid name for a variable or function.

//TODO: Modify regular expression to support things like _meep

const char * ILLEGALNAMES = "[[:digit:]+[:print:]*]";
// Illegal names begin with a digit. Things that being with digits are bad.

const char * CHARACTER = "\"[[:print:]]\"";
// Characters consist of a single character enclosed in quotation marks.

/*
.               ,.
T."-._..---.._,-"/|
l|"-.  _.v._   (" |
[l /.'_ \; _~"-.`-t
Y " _(o} _{o)._ ^.|
j  T  ,-<v>-.  T  ]
\  l ( /-^-\ ) !  !
 \. \.  "~"  ./  /c-..,__
   ^r- .._ .- .-"  `- .  ~"--.
    > \.                      \
    ]   ^.                     \
    3  .  ">            .       Y  -Row
,.__.--._   _j   \ ~   .         ;       |
(    ~"-._~"^._\   ^.    ^._      I     . l
"-._ ___ ~"-,_7    .Z-._   7"   Y      ;  \        _
/"   "~-(r r  _/_--._~-/    /      /,.--^-._   / Y
"-._    '"~~~>-._~]>--^---./____,.^~        ^.^  !
~--._    '   Y---.                        \./
   ~~--._  l_   )                        \
         ~-._~~~---._,____..---           \
             ~----"~       \
*/
