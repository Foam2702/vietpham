#include"Header.h"

bool LaNamNhuan(int nam)
{
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
        return true;
    return false;
}


bool LaNgayHopLe(int ngay, int thang, int nam)
{
    if (ngay <= 0 || thang <= 0 || nam <= 0)
        return false;
    switch (ngay)
    {
    case 31:
        if (thang == 2 || thang == 4 || thang == 6 || thang == 9 || thang == 11)
            return false;
    case 30:
        if (thang == 2)
            return false;
    case 29:
        if (thang == 2 && LaNamNhuan(nam) == false)
            return false;
    }
    return true;
}



int ThuTuNgayTrongNam(int ngay, int thang, int nam)
{
    int temp = ngay;
    for (int i = 1; i < thang; i++)
    {
        switch (i)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            temp += 30;
            break;
        case 2:
            temp += 28 + ((nam % 4 == 0 && nam % 100) || (nam % 400 == 0));
            break;
        default:
            temp += 31;
        }
    }
    return temp;
}
int ThuTuNgayTrongTuan(int ngay, int thang, int nam)
{
    int value;
    value = (ngay + ((153 * (thang + 12 * ((14 - thang) / 12) - 3) + 2) / 5) +
        (365 * (nam + 4800 - ((14 - thang) / 12))) +
        ((nam + 4800 - ((14 - thang) / 12)) / 4) -
        ((nam + 4800 - ((14 - thang) / 12)) / 100) +
        ((nam + 4800 - ((14 - thang) / 12)) / 400) - 32045) % 7;

    if (value == 0)
        return 2;
    else if (value == 1)
        return 3;
    else if (value == 2)
        return 4;
    else if (value == 3)
        return 5;
    else if (value == 4)
        return 6;
    else if (value == 5)
        return 7;
    return  8;
}
void ngaySau(int ngay, int thang, int nam, int& ngaySau, int& thangSau, int& namSau)
{
    ngaySau = ngay;
    thangSau = thang;
    namSau = nam;
    switch (thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10:
        if (ngay == 31)
        {
            thangSau++;
            ngaySau = 0;
        }
        break;
    case 4: case 6: case 9: case 11:
        if (ngay == 30)
        {
            ngaySau = 0;
            thangSau++;
        }

        break;
    case 2:
        if ((LaNamNhuan(nam) == true && ngay == 29) || (LaNamNhuan(nam) == false && ngay == 28))
        {
            ngaySau = 0;
            thangSau++;
        }

        break;
    case 12:
        if (ngay == 31)
        {
            ngaySau = 0;
            thangSau = 1;
            namSau++;
            break;
        }
    }
    ngaySau++;
    cout << "Ngay hom sau: " << ngaySau << "/" << thangSau << "/" << namSau << endl;
}
void NgayTruoc(int ngay, int thang, int nam, int& ngayTruoc, int& thangTruoc, int& namTruoc)
{
    ngayTruoc = ngay;
    thangTruoc = thang;
    namTruoc = nam;
    if (ngay == 1)
    {
        switch (thang)
        {
        case 2: case 4: case 6: case 8: case 9: case 11:
            ngayTruoc = 31;
            break;
        case 5: case 7: case 10: case 12:
            ngayTruoc = 30;
            break;
        case 3:
            if (LaNamNhuan(nam) == true)
                ngayTruoc = 29;
            else
                ngayTruoc = 28;
            break;
        case 1:
            ngayTruoc = 31;
            thangTruoc = 13;
            namTruoc--;
            break;
        }
        thangTruoc--;
    }
    else
        ngayTruoc--;
    cout << "Ngay hom truoc : " << ngayTruoc << "/" << thangTruoc << "/" << namTruoc << endl;
}