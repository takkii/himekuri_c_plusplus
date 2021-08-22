#include "all.h"

int main(void)
{
    try{
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

        // OneYear �� 365 days.
        int OneYear_Days = 365;

        int redays = nowlt->tm_yday;
        int redays_mini = OneYear_Days - redays;

        string tim = "���ݎ���";
        string gantan = "���N��1��1���܂ł���";
        string aisatu = " ���ł�";
        string number = "���߂��萔���ԍ�";
        string week = "�j��";

        // week Sun ~ Sat
        time_t timer;
        struct tm *t_st;
        const char *wday[] = {"��", "��", "��", "��", "��", "��", "�y"};

        // Month �a����
        const char* wmonth[] = { "�r��", "�@��", "�퐶", "�K��", "�H��", "������", "����", "�t��", "����", "�_����", "����", "�t��"
        };

        time(&timer);
        t_st = localtime(&timer);

        stringstream ss;
        stringstream ssd;

        // version number
        ss << 1;
        ssd << 2;
        string str_num = ss.str();
        string str_dd = ssd.str();
        string comma = " : ";

        // version number comma
        string number_comma = ".1.";

        string himekuri = number + comma + str_num + number_comma + str_dd;

        cout << tim << comma << result << comma << wday[t_st->tm_wday] << week << comma << wmonth[t_st->tm_mon] << endl;
        cout << gantan << comma << redays_mini << aisatu << endl;
        cout << result_reiwa << comma << result_r << endl;
        cout << himekuri << endl;

        // C++ version info.
        long cpp20 = 202002L;
        long cpp17 = 201703L;
        long cpp17_2 = 201709L;
        long cpp14 = 201402L;
        long cpp11 = 201103L;
        long cpp98 = 199711L;

        // long type �� string type.
        string cpp_ver = to_string(__cplusplus);

        if (cpp_ver.compare(to_string(cpp20)) == 0)
            cout << "���݂� C++ : C++20" << endl;
        else if (cpp_ver.compare(to_string(cpp17)) == 0)
            cout << "���݂� C++ : C++17" << endl;
        else if (cpp_ver.compare(to_string(cpp17_2)) == 0)
            cout << "���݂� C++ : C++17" << endl;
        else if (cpp_ver.compare(to_string(cpp14)) == 0)
            cout << "���݂� C++ : C++14" << endl;
        else if (cpp_ver.compare(to_string(cpp11)) == 0)
            cout << "���݂� C++ : C++11" << endl;
        else if (cpp_ver.compare(to_string(cpp98)) == 0)
            cout << "���݂� C++ : C++98" << endl;
        else
            cout << "���݂� C++ : pre-standard C++" << endl;

    } catch (runtime_error& e) {
        cout << "runtime_error : " << e.what() << endl;
    } catch (exception& e) {
        cout << "some exception : " << e.what() << endl;
    }
    exit(0);
}
