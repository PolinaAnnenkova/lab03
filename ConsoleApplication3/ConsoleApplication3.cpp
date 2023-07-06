#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Header.h"
#include "Header1.h"
using namespace std;
/*const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 - 2;
const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;*/
size_t number_count, bin_count, zv, zv_max = 0;
//void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black");
/*vector<string> COLORS = {"#DC143C", "#98FB98", "#20B2AA", "#00FFFF", "#FFFF00", "#FF00FF",
                                   "#FFDEAD", "#D2691E", "#8000FF", "#987654", "#7B68EE", "#FFEC8B",
                                   "#9FE2BF", "#D2B48C", "#464531", "#C1876B", "#CDB891", "#734A12" };

string get_random_color() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, COLORS.size() - 1);
    return COLORS[dist(rng)];
}*/
vector<double>input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}
/*void find_minmax(const vector<double> numbers, double& min, double& max)
{
    if (numbers.size() == 0)
    {
        min = 0;
        max = 0;
    }
    else
    {
        min = numbers[0]; max = numbers[0];
        for (int i = 0; i < numbers.size(); i++)
        {
            if (min > numbers[i])
            {
                min = numbers[i];
            }
            if (max < numbers[i])
            {
                max = numbers[i];
            }
        }
    }
}*/
vector <size_t> make_histogram(vector<double>numbers, size_t bin_count)

{

    double h; double min, max;

    find_minmax(numbers, min, max); h = (max - min) / bin_count;

    vector <size_t> bins(bin_count); for (double number : numbers)

    {

        for (size_t i = 0; i < bin_count; i++)

        {

            if ((number >= (min + h * (i))) && (number < (min + h * (i + 1))))

            {

                bins[i]++;

            }

            if (i >= bin_count)

            {

                i = bin_count - 1;

            }

        }

        if (number == max)

        {

            bins[bin_count - 1]++;

        }

    }

    return bins;

}
void print(vector<size_t>bins, size_t bin_count) {
    size_t max_count = 0;
    bool f = false;
    for (size_t i = 0; i < bin_count; i++)
    {

        if (bins[i] > max_count)
        {
            max_count = bins[i];
            if (bins[i] > MAX_ASTERISK)
                f = true;
        }
    }

    if (f == true)
    {
        for (size_t i = 0; i < bin_count; i++)
        {
            {
                zv = (int)MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
                if (zv_max < zv)
                {
                    zv_max = zv;
                }
            }
        }
    }
    else
    {
        zv_max = max_count;
    }

    int  minus = 0;
    cout << "+";
    while (minus != (zv_max + 5))
    {
        cout << "-";
        minus++;
    }
    minus = 0;
    cout << "+" << endl;



    for (size_t i = 0; i < bin_count; i++)
    {
        int count_stars = 0;
        cout << "|";
        if (bins[i] < 100) {
            cout << ' ';
        }
        if (bins[i] < 10) {
            cout << ' ';
        }

        cout << bins[i] << "|";


        if (f)
        {
            bins[i] = (int)MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
        }

        for (size_t j = 0; j < bins[i]; j++)
        {
            cout << "*";
            count_stars++;
        }

        while (count_stars != zv_max)
        {
            cout << " ";
            count_stars++;
        }

        cout << " " << "|" << endl;
    }

    cout << "+";
    while (minus != (zv_max + 5))
    {
        cout << "-";
        minus++;
    }
    cout << "+" << endl;
}


/*void svg_begin(double width, double height)

{

    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";

    cout << "<svg width='" << width << "' height='" << height << "' "

        << "viewBox='0 0 " << width << " " << height << "' "

        << "xmlns='http://www.w3.org/2000/svg'>\n";

}*/

/*void svg_end()

{
    cout << "</svg>\n";

}*/



/*void svg_text(double left, double baseline, string text)

{

    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";

}*/
/*void svg_ramka(double x1 = 0, double y1 = 5, double x2 = 30, double y2 = 5, string stroke = "black") {
    cout << "<line x1='" << x1 << "' y1='" << y1 << "' x2= '" << x2 << "' y2='" << y2 << "' stroke='" << stroke << "' stroke-dasharray='" << (10, 10);
    cout << "'/>";

}*/


/*void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke;
    cout << "' fill='" << fill;
    cout << "'/>";
}*/
void show_histogram_svg(const vector<size_t>& bins) {

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    //svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
    //svg_rect(TEXT_WIDTH, 0, bins[0] * BLOCK_WIDTH, BIN_HEIGHT);
    size_t max_count = bins[0];
    for (size_t i = 1; i < bin_count; i++) {
        if (max_count < bins[i])
            max_count = bins[i];
    }
    double top = 0;
    svg_ramka(8, 5, static_cast<size_t>(IMAGE_WIDTH * 0.5) + TEXT_WIDTH + 30, 5, "black");
    svg_ramka(8, 5, 8, (BIN_HEIGHT + 10) * bin_count, "black");//bok
    svg_ramka(8, (BIN_HEIGHT + 10) * bin_count - 3, static_cast<size_t>(IMAGE_WIDTH * 0.5) + TEXT_WIDTH + 30, (BIN_HEIGHT + 10) * bin_count - 3, "black");
    svg_ramka(static_cast<size_t>(IMAGE_WIDTH * 0.5) + TEXT_WIDTH + 28, 5, static_cast<size_t>(IMAGE_WIDTH * 0.5) + TEXT_WIDTH + 30, (BIN_HEIGHT + 10) * bin_count, "black");//bok
    for (size_t bin : bins) {
        const double bin_width = static_cast<size_t>(IMAGE_WIDTH * 0.5 * (static_cast<double>(bin) / max_count));

        svg_text(TEXT_LEFT, top + TEXT_BASELINE + 10, to_string(bin));
        svg_rect(TEXT_WIDTH + 10, top + 15, bin_width, BIN_HEIGHT, "#6699FF", get_random_color());
        top += BIN_HEIGHT;
    }

    svg_end();
}



//int main()
//{
//
//    cerr << "Enter number count: ";
//    cin >> number_count;
//    const vector <double>& numbers = input_numbers(number_count);
//    cerr << "Enter bin count: ";
//    cin >> bin_count;
//    vector<size_t> bins(bin_count);
//    double min, max;
//    find_minmax(numbers, min, max);
//    bins = make_histogram(numbers, bin_count);
//    //print(bins, bin_count);
//    show_histogram_svg(bins);
//
//    return 0;
//}
