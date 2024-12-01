#include<bits/stdc++.h>


using namespace std;
// khai bao cau truc sinhvien
struct SinhVien
{
    int MSSV;
    char HoTen[30];
    float DTK;
};

// Tao cau truc danh sach lien ket don
struct node
{
    SinhVien info;
    node* next;
};
typedef node NODE;

struct list
{
    node *pHead;
    node *pTail;
};
typedef struct list LIST;

//Khoi tao danh sach lhd
void init(list& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

// Tao node moi
node* makenode(SinhVien s)
{
    node* p = new node;
    if (p == NULL)
    {
        cout << "\nKhong du bo nho";
        return NULL;
    }
    p->info.MSSV = s.MSSV;
    strcpy(p->info.HoTen, s.HoTen);
    p->info.DTK = s.DTK;
    p->next = NULL;
    return p;

}

void Nhap(SinhVien &s)
{
    cout << "Ma so sinh vien: ";				cin >>s.MSSV;
    cout << "Ho va ten: ";	fflush(stdin);	gets(s.HoTen);
    cout << "Diem trung binh: ";			cin >> s.DTK;

}

void AddLast(list &l, node* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->next = p;
        l.pTail = p;
    }

}
void InputList(list& l)
{
    int n;
    SinhVien s;
    do
    {
        cout <<  "\nNhap so luong sinh vien:";			cin >> n;
        if (n <= 0)
            cout << "So luong sinh vien phai lon hon 0. Vui long nhap lai.";
    } while (n <= 0);
    for (int i = 1; i <= n; i++)
    {
        node* p;
        cout << "\nNhap thong tin sinh vien thu " << i << endl;
        Nhap(s);
        p = makenode(s);
        AddLast(l, p);
    }

}
void Xuat(SV s)
{
    cout << s.MSSV << "\t" << s.HoTen << "\t\t" << s.DTK << endl;
}
void OutputList(list l)
{
    cout << endl << "MSSV\tHo va ten\tDiem tong ket" << endl;
    for (node* i = l.pHead; i != NULL; i = i->next)
        Xuat(i->info);
}

void RemoveFirst(list& l)
{
    node* p = l.pHead;
    if (l.pHead == NULL)
        cout << "\nDanh sach rong.";
    else
    {
        l.pHead = p->next;
        delete p;
       }
}
void Xoa(list& l)
{
    int x;
    cout <<"\nNhap MSSV can xoa: ";	cin >> x;
    if (l.pHead == NULL)
    {
        cout <<"\nDanh sach rong.";
        return;
    }
    if (l.pHead->info.MSSV == x)
    {
        cout << "Xoa thanh cong.\n";
        RemoveFirst(l);
        OutputList(l);
        return;
    }
    if (l.pTail->info.MSSV == x)
    {
        cout << "Xoa thanh cong.\n";
        RemoveLast(l);
        OutputList(l);
        return;
    }
    node* q = l.pHead->next;
    node* r = l.pHead;
    while (q != NULL)
    {
        if (q->info.MSSV == x)
        {
            r->next = q->next;
            delete q;
            cout << "Xoa thanh cong.\n";
            OutputList(l);
            return;
        }
        r = q;
        q = q->next;
    }
    cout << "Khong ton tai MSSV can xoa.\n";
}

void SolectionSort(list l)
{
    node* max;
    for (node* i = l.pHead; i != l.pTail; i = i->next)
    {
        max = i;
        for (node* j = i->next; j != NULL; j = j->next)
            if (j->info.DTK > max->info.DTK)
                    max = j;
        swap(i->info, max->info);
    }
}

void Them(list& l)
{
    node* p, * r, * q;
    SinhVien x;
    cout << "Nhap thong tin sinh vien can them:\n";
    Nhap(x);
    cout << "\nThem thanh cong.\n";
    p = makenode(x);
    if (l.pHead->info.DTK > x.DTK)
    {
        AddFirst(l, p);
        OutputList(l);
        return;
    }
    if (l.pTail->info.DTK < x.DTK)
    {
        AddLast(l, p);
        OutputList(l);
        return;
    }
    r = l.pHead;
    q = l.pHead->next;
    while (q != NULL)
    {
        if (q->info.DTK < x.DTK)
        {
            r = q;
            q = q->next;
        }
        else
        {
            r->next = p;
            p->next = q;
            OutputList(l);
            return;
        }
    }

}
int main()
{
	list l;
	init(l);
	InputList(l);
	OutputList(l);
	RemoveFirst(l);
	Xoa(l);
	SolectionSort(l);
	Them(l);
}
