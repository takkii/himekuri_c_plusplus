#include "all.h"

int main(void)
{
    time_t now = time(nullptr);
    const tm* nowlt = localtime(&now);

    stringstream x;
    x<<"R0";
    x<<nowlt->tm_year-118;
    x<<".";
    x<<nowlt->tm_mon+1;
    x<<".";
    x<<nowlt->tm_mday;

    string result_r = x.str();

    stringstream y;
    y<<"令和";
    y<<nowlt->tm_year-118;
    y<<"年";
    y<<nowlt->tm_mon+1;
    y<<"月";
    y<<nowlt->tm_mday;
    y<<"日";

    string result_reiwa = y.str();


    stringstream z;
    z<<"20";
    z<<nowlt->tm_year-100;
    z<<"年";
    z<<nowlt->tm_mon+1;
    z<<"月";
    z<<nowlt->tm_mday;
    z<<"日：";
    z<<nowlt->tm_hour;
    z<<"時";
    z<<nowlt->tm_min;
    z<<"分";
    z<<nowlt->tm_sec;
    z<<"秒";

    string result = z.str();

    int redays = nowlt->tm_yday;
    int redays_mini = 365-redays;

    string tim = "時刻を表示:";
    string gantan = "来年の1月1日まであと: ";
    string aisatu = " 日です";
    string number = "日めくり数え番号 : ";
    string version = "1.0.0";
    string comma = " : ";

    string himekuri = number + version;

    cout << tim << result << endl;
    cout << gantan << redays_mini << aisatu << endl;
    cout << result_reiwa << comma << result_r << endl;
    cout << himekuri << endl;

    return 0;
}
