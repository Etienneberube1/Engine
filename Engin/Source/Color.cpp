#include <Color.h>

project::Color::Color(uchar red, uchar green, uchar blue) :
    Color(red, green, blue, 255)
{
}

project::Color::Color(uchar red, uchar green, uchar blue, uchar alpha) :
    red(red), green(green), blue(blue), alpha(alpha)
{
}

void project::Color::Set(const Color& other)
{
    red = other.red;
    green = other.green;
    blue = other.blue;
    alpha = other.alpha;
}

const project::Color& project::Color::MAROON = project::Color(128, 0, 0);
const project::Color& project::Color::DARKRED = project::Color(139, 0, 0);
const project::Color& project::Color::BROWN = project::Color(165, 42, 42);
const project::Color& project::Color::FIREBRICK = project::Color(178, 34, 34);
const project::Color& project::Color::CRIMSON = project::Color(220, 20, 60);
const project::Color& project::Color::RED = project::Color(255, 0, 0);
const project::Color& project::Color::TOMATO = project::Color(255, 99, 71);
const project::Color& project::Color::CORAL = project::Color(255, 127, 80);
const project::Color& project::Color::INDIANRED = project::Color(205, 92, 92);
const project::Color& project::Color::LIGHTCORAL = project::Color(240, 128, 128);
const project::Color& project::Color::DARKSALMON = project::Color(233, 150, 122);
const project::Color& project::Color::SALMON = project::Color(250, 128, 114);
const project::Color& project::Color::LIGHTSALMON = project::Color(255, 160, 122);
const project::Color& project::Color::ORANGERED = project::Color(255, 69, 0);
const project::Color& project::Color::DARKORANGE = project::Color(255, 140, 0);
const project::Color& project::Color::ORANGE = project::Color(255, 165, 0);
const project::Color& project::Color::GOLD = project::Color(255, 215, 0);
const project::Color& project::Color::DARKGOLDENROD = project::Color(184, 134, 11);
const project::Color& project::Color::GOLDENROD = project::Color(218, 165, 32);
const project::Color& project::Color::PALEGOLDENROD = project::Color(238, 232, 170);
const project::Color& project::Color::DARKKHAKI = project::Color(189, 183, 107);
const project::Color& project::Color::KHAKI = project::Color(240, 230, 140);
const project::Color& project::Color::OLIVE = project::Color(128, 128, 0);
const project::Color& project::Color::YELLOW = project::Color(255, 255, 0);
const project::Color& project::Color::YELLOWGREEN = project::Color(154, 205, 50);
const project::Color& project::Color::DARKOLIVEGREEN = project::Color(85, 107, 47);
const project::Color& project::Color::OLIVEDRAB = project::Color(107, 142, 35);
const project::Color& project::Color::LAWNGREEN = project::Color(124, 252, 0);
const project::Color& project::Color::CHARTREUSE = project::Color(127, 255, 0);
const project::Color& project::Color::GREENYELLOW = project::Color(173, 255, 47);
const project::Color& project::Color::DARKGREEN = project::Color(0, 100, 0);
const project::Color& project::Color::GREEN = project::Color(0, 128, 0);
const project::Color& project::Color::FORESTGREEN = project::Color(34, 139, 34);
const project::Color& project::Color::LIME = project::Color(0, 255, 0);
const project::Color& project::Color::LIMEGREEN = project::Color(50, 205, 50);
const project::Color& project::Color::LIGHTGREEN = project::Color(144, 238, 144);
const project::Color& project::Color::PALEGREEN = project::Color(152, 251, 152);
const project::Color& project::Color::DARKSEAGREEN = project::Color(143, 188, 143);
const project::Color& project::Color::MEDIUMSPRINGGREEN = project::Color(0, 250, 154);
const project::Color& project::Color::SPRINGGREEN = project::Color(0, 255, 127);
const project::Color& project::Color::SEAGREEN = project::Color(46, 139, 87);
const project::Color& project::Color::MEDIUMAQUAMARINE = project::Color(102, 205, 170);
const project::Color& project::Color::MEDIUMSEAGREEN = project::Color(60, 179, 113);
const project::Color& project::Color::LIGHTSEAGREEN = project::Color(32, 178, 170);
const project::Color& project::Color::DARKSLATEGRAY = project::Color(47, 79, 79);
const project::Color& project::Color::TEAL = project::Color(0, 128, 128);
const project::Color& project::Color::DARKCYAN = project::Color(0, 139, 139);
const project::Color& project::Color::AQUA = project::Color(0, 255, 255);
const project::Color& project::Color::CYAN = project::Color(0, 255, 255);
const project::Color& project::Color::LIGHTCYAN = project::Color(224, 255, 255);
const project::Color& project::Color::DARKTURQUOISE = project::Color(0, 206, 209);
const project::Color& project::Color::TURQUOISE = project::Color(64, 224, 208);
const project::Color& project::Color::MEDIUMTURQUOISE = project::Color(72, 209, 204);
const project::Color& project::Color::PALETURQUOISE = project::Color(175, 238, 238);
const project::Color& project::Color::AQUAMARINE = project::Color(127, 255, 212);
const project::Color& project::Color::POWDERBLUE = project::Color(176, 224, 230);
const project::Color& project::Color::CADETBLUE = project::Color(95, 158, 160);
const project::Color& project::Color::STEELBLUE = project::Color(70, 130, 180);
const project::Color& project::Color::CORNFLOWERBLUE = project::Color(100, 149, 237);
const project::Color& project::Color::DEEPSKYBLUE = project::Color(0, 191, 255);
const project::Color& project::Color::DODGERBLUE = project::Color(30, 144, 255);
const project::Color& project::Color::LIGHTBLUE = project::Color(173, 216, 230);
const project::Color& project::Color::SKYBLUE = project::Color(135, 206, 235);
const project::Color& project::Color::LIGHTSKYBLUE = project::Color(135, 206, 250);
const project::Color& project::Color::MIDNIGHTBLUE = project::Color(25, 25, 112);
const project::Color& project::Color::NAVY = project::Color(0, 0, 128);
const project::Color& project::Color::DARKBLUE = project::Color(0, 0, 139);
const project::Color& project::Color::MEDIUMBLUE = project::Color(0, 0, 205);
const project::Color& project::Color::BLUE = project::Color(0, 0, 255);
const project::Color& project::Color::ROYALBLUE = project::Color(65, 105, 225);
const project::Color& project::Color::BLUEVIOLET = project::Color(138, 43, 226);
const project::Color& project::Color::INDIGO = project::Color(75, 0, 130);
const project::Color& project::Color::DARKSLATEBLUE = project::Color(72, 61, 139);
const project::Color& project::Color::SLATEBLUE = project::Color(106, 90, 205);
const project::Color& project::Color::MEDIUMSLATEBLUE = project::Color(123, 104, 238);
const project::Color& project::Color::MEDIUMPURPLE = project::Color(147, 112, 219);
const project::Color& project::Color::DARKMAGENTA = project::Color(139, 0, 139);
const project::Color& project::Color::DARKVIOLET = project::Color(148, 0, 211);
const project::Color& project::Color::DARKORCHID = project::Color(153, 50, 204);
const project::Color& project::Color::MEDIUMORCHID = project::Color(186, 85, 211);
const project::Color& project::Color::PURPLE = project::Color(128, 0, 128);
const project::Color& project::Color::THISTLE = project::Color(216, 191, 216);
const project::Color& project::Color::PLUM = project::Color(221, 160, 221);
const project::Color& project::Color::VIOLET = project::Color(238, 130, 238);
const project::Color& project::Color::MAGENTA = project::Color(255, 0, 255);
const project::Color& project::Color::ORCHID = project::Color(218, 112, 214);
const project::Color& project::Color::MEDIUMVIOLETRED = project::Color(199, 21, 133);
const project::Color& project::Color::PALEVIOLETRED = project::Color(219, 112, 147);
const project::Color& project::Color::DEEPPINK = project::Color(255, 20, 147);
const project::Color& project::Color::HOTPINK = project::Color(255, 105, 180);
const project::Color& project::Color::LIGHTPINK = project::Color(255, 182, 193);
const project::Color& project::Color::PINK = project::Color(255, 192, 203);
const project::Color& project::Color::ANTIQUEWHITE = project::Color(250, 235, 215);
const project::Color& project::Color::BEIGE = project::Color(245, 245, 220);
const project::Color& project::Color::BISQUE = project::Color(255, 228, 196);
const project::Color& project::Color::BLANCHEDALMOND = project::Color(255, 235, 205);
const project::Color& project::Color::WHEAT = project::Color(245, 222, 179);
const project::Color& project::Color::CORNSILK = project::Color(255, 248, 220);
const project::Color& project::Color::LEMONCHIFFON = project::Color(255, 250, 205);
const project::Color& project::Color::LIGHTGOLDENRODYELLOW = project::Color(250, 250, 210);
const project::Color& project::Color::LIGHTYELLOW = project::Color(255, 255, 224);
const project::Color& project::Color::SADDLEBROWN = project::Color(139, 69, 19);
const project::Color& project::Color::SIENNA = project::Color(160, 82, 45);
const project::Color& project::Color::CHOCOLATE = project::Color(210, 105, 30);
const project::Color& project::Color::PERU = project::Color(205, 133, 63);
const project::Color& project::Color::SANDYBROWN = project::Color(244, 164, 96);
const project::Color& project::Color::BURLYWOOD = project::Color(222, 184, 135);
const project::Color& project::Color::TAN = project::Color(210, 180, 140);
const project::Color& project::Color::ROSYBROWN = project::Color(188, 143, 143);
const project::Color& project::Color::MOCCASIN = project::Color(255, 228, 181);
const project::Color& project::Color::NAVAJOWHITE = project::Color(255, 222, 173);
const project::Color& project::Color::PEACHPUFF = project::Color(255, 218, 185);
const project::Color& project::Color::MISTYROSE = project::Color(255, 228, 225);
const project::Color& project::Color::LAVENDERBLUSH = project::Color(255, 240, 245);
const project::Color& project::Color::LINEN = project::Color(250, 240, 230);
const project::Color& project::Color::OLDLACE = project::Color(253, 245, 230);
const project::Color& project::Color::PAPAYAWHIP = project::Color(255, 239, 213);
const project::Color& project::Color::SEASHELL = project::Color(255, 245, 238);
const project::Color& project::Color::MINTCREAM = project::Color(245, 255, 250);
const project::Color& project::Color::SLATEGRAY = project::Color(112, 128, 144);
const project::Color& project::Color::LIGHTSLATEGRAY = project::Color(119, 136, 153);
const project::Color& project::Color::LIGHTSTEELBLUE = project::Color(176, 196, 222);
const project::Color& project::Color::LAVENDER = project::Color(230, 230, 250);
const project::Color& project::Color::FLORALWHITE = project::Color(255, 250, 240);
const project::Color& project::Color::ALICEBLUE = project::Color(240, 248, 255);
const project::Color& project::Color::GHOSTWHITE = project::Color(248, 248, 255);
const project::Color& project::Color::HONEYDEW = project::Color(240, 255, 240);
const project::Color& project::Color::IVORY = project::Color(255, 255, 240);
const project::Color& project::Color::AZURE = project::Color(240, 255, 255);
const project::Color& project::Color::SNOW = project::Color(255, 250, 250);
const project::Color& project::Color::BLACK = project::Color(0, 0, 0);
const project::Color& project::Color::DIMGREY = project::Color(105, 105, 105);
const project::Color& project::Color::GREY = project::Color(128, 128, 128);
const project::Color& project::Color::DARKGREY = project::Color(169, 169, 169);
const project::Color& project::Color::SILVER = project::Color(192, 192, 192);
const project::Color& project::Color::LIGHTGREY = project::Color(211, 211, 211);
const project::Color& project::Color::GAINSBORO = project::Color(220, 220, 220);
const project::Color& project::Color::WHITESMOKE = project::Color(245, 245, 245);
const project::Color& project::Color::WHITE = project::Color(255, 255, 255);