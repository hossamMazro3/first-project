#include<bits/stdc++.h>
#include<fstream>
#include<map>
using namespace std;
class Inventory
{
    int id,amount,price,shelfnum;
    string name,type;
//Encapsulation
public:
    //constructor
    Inventory (int i=0,string n=" ",int p=0,string t=" ",int a=0,int s=0)
    {
        id=i;
        name=n;
        price=p;
        type=t;
        amount=a;
        shelfnum=s;
    }
    //getter
    int getid () const
    {
        return id;
    }
    int getamount () const
    {
        return amount;
    }
    int getprice () const
    {
        return price;
    }
    string getname () const
    {
        return name;
    }
    string gettype () const
    {
        return type;
    }
    int getshelfnum () const
    {
        return shelfnum;
    }
    //setter
    void setid(int id)
    {
        this->id=id;
    }
    void setamount(int amount)
    {
        this->amount=amount;
    }
    void setprice(int price)
    {
        this->price=price;
    }
    void setname(string name)
    {
        this->name=name;
    }
    void settype(string type)
    {
        this->type=type;
    }
    void setshelfnum(int shelfnum)
    {
        this->shelfnum=shelfnum;
    }
//operator overloading
    bool operator==(Inventory b)
    {
        return((this->name==b.getname())&&(this->type==b.gettype())&&(this->shelfnum==b.getshelfnum()));
    }
    friend ostream & operator<< (ostream & out,Inventory & b)
    {
        out<<b.getid()<<", "<<b.getname()<<", "<<b.getprice()<<", "<<b.gettype()<<", "<<b.getamount()<<", "<<b.getshelfnum()<<endl;
    }
    friend istream & operator>> (istream & in,Inventory & b)
    {
        in>>b.id>>b.name>>b.price>>b.type>>b.amount>>b.shelfnum;
        return in;
    }
    friend fstream & operator<< (fstream & file,Inventory & b){
    file<<b.getid()<<","<<b.getname()<<","<<b.getprice()<<","<<b.gettype()<<","<<b.getamount()<<","<<b.getshelfnum()<<endl;
    return file;

    }

};
fstream file;
Inventory product;
void convertStringToProduct(const string record)
{
    stringstream strs(record);
    string p_id,p_name,p_price,p_type,p_amount,p_shelfnum;
    getline(strs,p_id, ',');
    getline(strs,p_name, ',');
    getline(strs,p_price, ',');
    getline(strs,p_type, ',');
    getline(strs,p_amount, ',');
    getline(strs,p_shelfnum, '\n');

    //convert string to id

    product.setid(atoi(p_id.c_str()));
    product.setname(p_name);
    product.setprice(atoi(p_price.c_str()));
    product.settype(p_type);
    product.setamount(atoi(p_amount.c_str()));
    product.setshelfnum(atoi(p_shelfnum.c_str()));

}

void search_for_product()
{
    file.open("data.txt",ios::in);
    if(!file)
    {
        cout<<"\nError404....";
        exit(1);
    }
    cout<<"Enter your ID: ";
    int key;
    cin>>key;
    string record;
    while(1)
    {
        file>>record;
        convertStringToProduct(record);
        if(product.getid()==key)
        {
            cout<<"Item Is Found \n";
            cout<<product;
            file.close();
            return;

        }
        if(file.eof())
        {
            break;
        }

    }
    cout<<"Not Found!!!! \n";
    file.close();
    return;
}

void modify()
{
    file.open("data.txt",ios::in);
    if(!file)
    {
        cout<<"\nError404....";
        exit(1);
    }
    Inventory data[100];
    string u_name;
    cout<<"Enter name of product to modify \n";
    cin>>u_name;
    string record;
    int c=0;
    while(1)
    {
        file>>record;
        if(file.eof())
        {
            break;
        }
        convertStringToProduct(record);
        data[c].setid(product.getid());
        data[c].setname(product.getname());
        data[c].setprice(product.getprice());
        data[c].settype(product.gettype());
        data[c].setamount(product.getamount());
        data[c].setshelfnum(product.getshelfnum());
        c++;

    }
    int i=0;
    for(; i<c; i++)
    {
        if(data[i].getname() ==u_name)
        {
            cout<<"old product info is : ";
            cout<<data[i];
            char y;
    cout<<"if you want to undo this operation enter 'y':- ";
    cin>>y;
    if(y =='y') {file.close(); }
    else{
            cout<<"\nEnter new product info : \n";
            cin>>data[i];
            }
            break;
        }
    }
    if(c==i){
        cout<<"Not found!...\n";
        return;
    }
    file.close();

    file.open("data.txt",ios::out);
    if(!file)
    {
        cout<<"\nError404....";
        exit(1);
    }
    for(int i=0; i<c; i++)
    {
        file<<data[i];
    }
    file.close();


}
void delete_product()
{
    file.open("data.txt",ios::in);
    if(!file)
    {
        cout<<"\nError404....";
        exit(1);
    }
    Inventory data[100];
    string u_name;
    cout<<"Enter name of product to delete \n";
    cin>>u_name;
    string record;
    int c=0;
    while(1)
    {
        file>>record;
        if(file.eof())
        {
            break;
        }
        convertStringToProduct(record);
        data[c].setid(product.getid());
        data[c].setname(product.getname());
        data[c].setprice(product.getprice());
        data[c].settype(product.gettype());
        data[c].setamount(product.getamount());
        data[c].setshelfnum(product.getshelfnum());
        c++;

    }
    int i=0;
    for(; i<c; i++)
    {
        if(data[i].getname() ==u_name)
        {
            cout<<"old product info is : ";
            cout<<data[i];
            cout<<"\n delete operation is done...."<<endl;
            break;
        }
    }
    if(c==i){
        cout<<"Not found!...\n";
        return;
    }

    //shifting
     char y;
    cout<<"if you want to undo this operation enter 'y':- ";
    cin>>y;
    if(y =='y') {file.close(); }
    else{
    for(int j=i;j<c;j++){
        data[j]=data[j+1];
    }
    c--;
    file.close();

    file.open("data.txt",ios::out);
    if(!file)
    {
        cout<<"\nError404....";
        exit(1);
    }
    for(int i=0; i<c; i++)
    {
        file<<data[i];
    }
    file.close();
    }


}
void Displayall()
{
    file.open("data.txt",ios::in);
    if(!file)
    {
        cout<<"\nError404....";
        exit(1);
    }
    Inventory data[100];
    string record;
    int c=0;
    while(true)
    {
        file>>record;
        if(file.eof())
        {
            break;
        }

        convertStringToProduct(record);
        data[c].setid(product.getid());
        data[c].setname(product.getname());
        data[c].setprice(product.getprice());
        data[c].settype(product.gettype());
        data[c].setamount(product.getamount());
        data[c].setshelfnum(product.getshelfnum());
        c++;

    }
    // selection sort
    int out,in,min;
    for(int out=0;out<c-1;out++){
        min=out;
        for(in=out+1;in<c;in++){
            if(data[in].getprice()<data[min].getprice())
                min=in;
        }
        swap(data[out],data[min]);
    }
    cout<<"These Items Sorted By Price \n";
    for(int j=0;j<c;j++)
        cout<<data[j];
file.close();
}
void addproduct()
{
    file.open("data.txt",ios::app);
    if(!file)
    {
        cout<<"\n Error404....";
        exit(1);
    }
    cout<<"\n Enter your product info :";
    cin>>product;
//write into file
    char y;
    cout<<"if you want to undo this operation enter 'y':- ";
    cin>>y;
    if(y =='y') {file.close();}
    else{
        file<<product.getid()<<","<<product.getname()<<","<<product.getprice()<<","<<product.gettype()<<","<<product.getamount()<<","<<product.getshelfnum()<<endl;
    file.close();
    }
}
int main()
{
    int choice;
    while(1)
    {
        cout<<endl<<"0 : Exit";
        cout<<endl<<"1 : Insert new product ";
        cout<<endl<<"2 : Display all products ";
        cout<<endl<<"3 : modify product ";
        cout<<endl<<"4 : Delete product ";
        cout<<endl<<"5 : Search for product( by ID ) ";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            addproduct();
            break;
        case 2:
            Displayall();
            break;
        case 3:
            modify();
            break;
        case 4:
            delete_product();
            break;
        case 5:
            search_for_product();
            break;
        default:
            cout<<"\n Invalid Input...";
            break;

        }
    }



}
