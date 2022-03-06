#include<iostream>
using namespace std;

int main()
{
    int ngay=0,thang=0, nam=0, ngaytruoc=0, ngaysau=0;
    //cau a
    do 
    {
        cout << "Hay nhap ngay : ";
        cin >> ngay;
        cout << "Hay nhap thang :";
        cin >> thang;
        cout << "Hay nhap nam :";
        cin >> nam;
       
        if (ngay < 0 || ngay>31 || thang < 0 || thang>12 || nam < 0)
        {
            cout << "Ngay thang nam khong hop le" << endl;
        }
    } while (ngay < 0 || ngay > 31 || thang < 0 || thang > 12 || nam < 0);


    //cau b
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
        cout << "Nam nhuan"<<endl;
    else
    {
        cout << "Nam khong nhuan"<<endl;
    }


    //cau c
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 11:cout << "Thang co 31 ngay"<<endl; break;
    case 4:
    case 6:
    case 9:
    case 10:
    case 12:cout << "Thang co 30 ngay"<<endl; break;
    case 2:
        if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
            cout << "Thang co 29 ngay" << endl;
        else
        {
            cout << "Thang co 28 ngay"<<endl;
        }
        break;
    }

    //cau d
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
    cout << "Ngay thu " << temp<<" trong nam" << endl;

    //cau e
    int value;
    value = (ngay + ((153 * (thang + 12 * ((14 - thang) / 12) - 3) + 2) / 5) +
        (365 * (nam+ 4800 - ((14 -thang) / 12))) +
        ((nam + 4800 - ((14 - thang) / 12)) / 4) -
        ((nam + 4800 - ((14 - thang) / 12)) / 100) +
        ((nam + 4800 - ((14 - thang) / 12)) / 400) - 32045) % 7;
    
    const char* weekday[] = {"2",  " 3","4","5","6","7","Chu nhat" };
    
   
    cout<<"Day la thu "<< weekday[value]<<" trong tuan" << endl;
     //cau f
   

    if (ngay == 1)
    {
        if ( thang == 1 || thang == 5 || thang == 7 || thang == 8 || thang == 11)

            ngaytruoc = 30;

        else if (thang == 2 || thang == 4 || thang == 6 || thang == 9 || thang == 10 || thang == 12)

            ngaytruoc = 31;

        else if (thang == 3)
        {
            if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
            {
                ngaytruoc = 29;
            }
            else  ngaytruoc = 28;
        }
        
    }
    else
        ngaytruoc = ngay - 1;
    cout << "Ngay truoc do la : " << ngaytruoc << " va ";
    
    

    //cau g

    
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
    {
        if (ngay == 31 && (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 11))

            ngaysau = 1;

        else if (ngay == 30 && (thang == 4 || thang == 6 || thang == 9 || thang == 10 || thang == 12))

            ngaysau = 1;

    
        else if (ngay == 29 && thang == 2)

                ngaysau = 1;

        else if (ngay == 28 && thang == 2)

                ngaysau = 29;
        else
            ngaysau = ngay + 1;
    }

    
    else 
    {
        if (ngay == 31 && (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 11))

            ngaysau = 1;

        else if (ngay == 30 && (thang == 4 || thang == 6 || thang == 9 || thang == 10 || thang == 12))

            ngaysau = 1;

        else if (ngay == 28 && thang == 2)

            ngaysau = 1;
        else
            ngaysau = ngay + 1;
    }
    
    

    cout << "Ngay ke tiep la : " << ngaysau;
    
    system("pause");
    
}