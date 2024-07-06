#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class Bill{
    private:
        string Item;
        int Rate;
        int Quantity;
    public:  
        Bill():Item(""),Rate(0),Quantity(0){}
    
    void setItem(string item){
        Item=item;
    }

    void setRate(int rate){
        Rate=rate;
    }

    void setQuantity(int quantity){
        Quantity=quantity;
    }

    string getItem(){
        return Item;
    }

    int getRate(){
        return Rate;
    }

    int getQuantity(){
        return Quantity;
    }
};

void additem(Bill b){
    bool close=false;
    while(!close){
        int choice;
        cout<<"\t 1. Add."<<endl;
        cout<<"\t 2. Close."<<endl;
        cout<<"\t 3. Enter Choice : ";
        cin>>choice;

        if(choice==1){
            system("cls");
            string item;
            int rate,quantity;
            cout<<"\t Enter Item Name: ";
            cin>>item;
            b.setItem(item);

            cout<<"\t Enter rate of item : ";
            cin>>rate;
            b.setRate(rate);

            cout<<"\t Enter quantity of item : ";
            cin>>quantity;
            b.setQuantity(quantity);

            ofstream out("D:/C++ Projects/Super market billing system/Bill.txt",ios::app);
            if(!out){
                cout<<"\t Error in opening file"<<endl;

            }
            else{
                out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuantity()<<endl<<endl;
            }
            out.close();
            cout<<"\t Item Added Successfully"<<endl;
            Sleep(3000);
        }
        else if(choice==2){
            system("cls");
            close=true;
            cout<<"\tBack to main menu!"<<endl;
            Sleep(3000);
        }

        }

    }

void printBill(){
    system("cls");
    int count=0;
    bool close=false;
    while(!close){
        system("cls");
        int choice;
        cout<<"\t 1. Add Bill."<<endl;
        cout<<"\t 2. Close Session."<<endl;
        cout<<"\t Enter choice: ";
        cin>>choice;

        if(choice==1){
            string item;
            int quantity;
            cout<<"\tEnter item: ";
            cin>>item;

            cout<<"\tEnter Quantity: ";
            cin>>quantity;

            ifstream in("D:/C++ Projects/Super market billing system/Bill.txt");
            ofstream out("D:/C++ Projects/Super market billing system/Bill Temp.txt");

            string line;
            bool found=false;
            while(getline(in,line)){
                stringstream ss;
                ss<<line;
                string itemName;
                int itemQuantity;
                int itemRate;
                char delimiter;
                ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuantity;

                if(item==itemName){
                    found=true;
                    if(quantity<=itemQuantity){
                        int amount=itemRate*quantity;
                        cout<<"\t Item | Rate | Quantity | Amount"<<endl;
                        cout<<"\t"<<itemName<<"\t"<<itemRate<<"\t"<<quantity<<"\t"<<amount<<endl;
                        int newQuantity=itemQuantity-quantity;
                        itemQuantity=newQuantity;
                        count+=amount;
                        
                        out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuantity<<endl<<endl;
                    }
                    else{
                        cout<<"\t Sorry, "<<item<<" Ended!"<<endl;                 
                    }
                }
                else{
                    out<<line<<endl;                        
                }
        }
        if(!found){
            cout<<"\tItem Not Available!"<<endl;
        }
        out.close();
        in.close();
        remove("D:/C++ Projects/Super market billing system/Bill.txt");
        rename("D:/C++ Projects/Super market billing system/Bill Temp.txt","D:/C++ Projects/Super market billing system/Bill.txt");
    }

    else if(choice==2){
        close=true;
        cout<<"\tCounting Total Bill"<<endl;

    }
    Sleep(3000);

}
system("cls");
cout<<endl<<endl;
cout<<"\t Total Bill ---------------------- : "<<count<<endl<<endl;
cout<<"\t THANKYOU FOR SHOPPING!"<<endl;
Sleep(5000);
}

int main(){
    Bill b;
    bool exit=false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\t    Welcome to Super Market Billing System"<<endl;
        cout<<"\t-->>*************************************<<--"<<endl;
        cout<<"\t\t 1. ADD ITEM."<<endl;
        cout<<"\t\t 2. PRINT BILL."<<endl;
        cout<<"\t\t 3. EXIT."<<endl;
        cout<<"\t\t Enter your choice: ";
        cin>>val;

        if(val==1){
            system("cls");
          additem(b);
          Sleep(3000);
        }

        else if(val==2){
            printBill();
        }

        else if(val==3){
            system("cls");
            exit=true;
            cout<<"\t GOOD DAY"<<endl;
            Sleep(3000);
        }
    }
}