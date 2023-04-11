#include <iostream>
#include <string>
using namespace std;

struct Product
{
    string name;
    int price;
    int quantity;

    // Nạp chồng toán tử nhập
    friend istream& operator>> (istream &is, Product &product) 
    {
        cout << "Nhap ten: ";
        is.ignore();
        getline(is, product.name);

        cout << "Nhap gia: ";
        is >> product.price;

        cout << "Nhap so luong: ";
        is >> product.quantity;

        return is;
    }

    // Nạp chồng toán tử xuất
    friend ostream& operator<< (ostream &os, Product product)
    {
        os << "Ten san pham: " << product.name;
        os << ", don gia: " << product.price;
        os << ", so luong: " << product.quantity;

        return os;
    }

};

// Khai báo các hàm
int show_menu();
void print_products(Product *products, int size);
void add_products(Product* &products, int &size);
void delete_products(Product* &products, int &size);

int main() 
{
    int size = 0;
    Product *products = new Product[size];
    
    while(true)
    {
        int choose = show_menu();

        system("cls");
        switch (choose)
        {
        case 1:
            print_products(products, size);
            break;
        case 2:
            add_products(products, size);
            break;
        case 3:
            delete_products(products, size);
            break;
        case 0:
            cout << "Bye bye!";
            return 0;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }

        cout << "Ban co muon tiep tuc khong? (1/0) ";
        bool is_continue;
        cin >> is_continue;

        if (!is_continue) {
            cout << "Bye bye!";
            break;
        }
    }

    return 0;
}

// Hàm menu chọn các chức năng
int show_menu() 
{
    system("cls");
    int chose;
    cout << "====== MENU =====" << endl;
    cout << "1. Xem danh sach san pham" << endl;
    cout << "2. Them san pham moi" << endl;
    cout << "3. Xoa san pham" << endl;
    cout << "0. Thoat chuong trinh" << endl;

    cout << "Lua chon cua ban la: " << endl;
    cin >> chose;

    return chose;
}

// Hàm in ra danh sách các sản phẩm
void print_products(Product *products, int size) 
{
    if (size == 0)
    {
        cout << "size = " << size << endl;
        cout << "Chua co san pham nao." << endl;
    } 
    else 
    {
        cout << "Danh sach san pham: " << endl;
        for (int i = 0; i < size; i++) 
        {
            cout << products[i] << endl;
        }
    }
}

// Hàm thêm sản phẩm mới
void add_products(Product* &products, int &size) 
{
    Product new_product;
    cout << "Nhap thong tin san pham moi: " << endl;
    cin >> new_product;

    int new_size = size + 1;
    Product *tmp_products = new Product[new_size];

    for (int i = 0; i < size; i++) 
    {
        tmp_products[i] = products[i];
    }
    tmp_products[new_size - 1] = new_product;

    delete[] products;
    products = tmp_products;
    size = new_size;

    cout << "Them san pham thanh cong!" << endl;
}


// Hàm xóa sản phẩm
void delete_products(Product* &products, int &size) 
{
    cout << "Nhap ten san pham can xoa: ";

    string deleted_name;
    cin.ignore();
    getline(cin, deleted_name);

    int deleted_index = -1;
    for (int i = 0; i < size; i++)
    {
        if (!deleted_name.compare(products[i].name)) 
        {
            deleted_index = i;
            break;
        }
    }

    if (deleted_index == -1)
    {
        cout << "Khong tim thay san pham!" << endl;
        return;
    }

    for (int i = deleted_index; i < size - 1; i++) 
    {
        products[i] = products[i + 1];
    }
    size--;

    Product *tmp_products = new Product[size];

    for(int i = 0; i < size; i++) 
    {
        tmp_products[i] = products[i];
    }

    delete[] products;
    products = tmp_products;

    cout << "Xoa thanh cong!" << endl;
}
