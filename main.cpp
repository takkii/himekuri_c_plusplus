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
    y<<"�ߘa";
    y<<nowlt->tm_year-118;
    y<<"�N";
    y<<nowlt->tm_mon+1;
    y<<"��";
    y<<nowlt->tm_mday;
    y<<"��";

    string result_reiwa = y.str();


    stringstream z;
    z<<"20";
    z<<nowlt->tm_year-100;
    z<<"�N";
    z<<nowlt->tm_mon+1;
    z<<"��";
    z<<nowlt->tm_mday;
    z<<"��" << " : ";
    z<<nowlt->tm_hour;
    z<<"��";
    z<<nowlt->tm_min;
    z<<"��";
    z<<nowlt->tm_sec;
    z<<"�b";

    string result = z.str();

    int redays = nowlt->tm_yday;
    int redays_mini = 365-redays;

    string tim = "���ݎ��� : ";
    string gantan = "���N��1��1���܂ł��� : ";
    string aisatu = " ���ł�";
    string number = "���߂��萔���ԍ� : ";
    string version = "1.0.0";
    string comma = " : ";

    string himekuri = number + version;

    cout << tim << result << endl;
    cout << gantan << redays_mini << aisatu << endl;
    cout << result_reiwa << comma << result_r << endl;
    cout << himekuri << endl;

    return 0;
}
