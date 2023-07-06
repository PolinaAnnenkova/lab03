#include "Header1.h"
/*int razn(int a, int b) {
	return a - b;
}*/
void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke;
    cout << "' fill='" << fill;
    cout << "'/>";
}
vector<string> COLORS = { "#DC143C", "#98FB98", "#20B2AA", "#00FFFF", "#FFFF00", "#FF00FF",
                                   "#FFDEAD", "#D2691E", "#8000FF", "#987654", "#7B68EE", "#FFEC8B",
                                   "#9FE2BF", "#D2B48C", "#464531", "#C1876B", "#CDB891", "#734A12" };
string get_random_color() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, COLORS.size() - 1);
    return COLORS[dist(rng)];
}
void svg_begin(double width, double height)

{

    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";

    cout << "<svg width='" << width << "' height='" << height << "' "

        << "viewBox='0 0 " << width << " " << height << "' "

        << "xmlns='http://www.w3.org/2000/svg'>\n";

}
void svg_end()

{
    cout << "</svg>\n";

}
void svg_text(double left, double baseline, string text)

{

    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";

}
void svg_ramka(double x1, double y1, double x2, double y2, string stroke) {
    cout << "<line x1='" << x1 << "' y1='" << y1 << "' x2= '" << x2 << "' y2='" << y2 << "' stroke='" << stroke << "' stroke-dasharray='" << (10, 10);
    cout << "'/>";

}
