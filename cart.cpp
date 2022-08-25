#include <iostream>
#include <vector>
#include "datamodel.h"
using namespace std;
vector<Product> allProducts={
    Product(1,"apple",25),
    Product(2,"banana",5),
    Product(3,"pineaaple",45),
    Product(4,"watermelon",70),
    Product(5,"kiwi",35),
    Product(6,"strawberry",25),
    Product(7,"tomato",40),
    Product(8,"brinjal",35),
    Product(9,"okra",40),
    Product(10,"carrot",60),
    Product(11,"potato",40),
    Product(12,"radish",30),
    Product(13,"milk (1 ltr)",56),
    Product(14,"almond milk(1 ltr)",200),
    Product(15,"curd (1 kg)",45),
    Product(16,"paneer(1 Kg)",300),
    Product(17,"bread_white",50),
    Product(18,"tostea Rusk",40),
};
Product* chooseproduct(int c){
    string productlist;
    int s=6*c;
    cout<<"Available Products are "<<endl;
    for(int i=s;i<s+6;i++){
        productlist.append(allProducts[i].getDisplatName());
    }
    cout<<productlist<<endl;
    cout<<"Press (e) key to exit the section--"<<endl;
    cout<<"________________"<<endl;
    string choice;
    cin>>choice;
    if(choice=="e"){
        return NULL;
    }
    for(int i=s;i<s+6;i++){
        if(choice==allProducts[i].shortname()){
            return &allProducts[i];
        }
    }
    cout<<"Product Not Found!"<<endl;
    return NULL;
}
bool checkout(Cart &cart){
    if(cart.isempty()){
        return false;
    }
    else{
        int total=cart.getTotal();
        int paid;
        cout<<"Pay in cash "<<endl;
        cin>>paid;
        if(paid>=total){
            cout<<"Change - "<<paid-total<<endl;
            cout<<"Thank you for shopping !"<<endl;
            return true;
        }
        else{
            cout<<"Not enough Cash!!!"<<endl;
            cout<<"Try again!!"<<endl;
            return false;
        }
    }
}
int main(){
    cout<<"Enter your name-";
    string name;
    cin>>name;
    cout<<"Welcome "<<name<<"!"<<endl;
    cout<<"Let's shopp....."<<endl;
    char action;
    Cart cart;
    while(true){
        cout<<"select an action-(a)dd item (v)iew cart (c)heckout "<<endl;
        cin>>action;
        if(action=='a'){
            //add to cart
            //first view all Products
            char cata;
            cout<<"Select a catagory- (f)uit (v)egetables (b)akery and diary"<<endl;
            cin>>cata;
            int c;
            if(cata=='f'){
                c=0;
            }
            else if(cata=='v'){
                c=1;
            }
            else{
                c=2;
            }
            Product *product=chooseproduct(c);
            if(product!=NULL){
                cout<<"Enter quantity to be added- "<<endl;
                int q;
                cin>>q;
                cout<<"Added to cart "<<q<<" x "<<product->getDisplatName()<<endl;
                cart.addProduct(*product,q);
            }

        }
        else if(action=='v'){
            //view cart
            cout<<"---------------------"<<endl;
            cout<<cart.viewcart()<<endl;
            cout<<"---------------------"<<endl;
        }
        else{
            //checkout
            cout<<cart.viewcart();
            char d;
            cout<<"Press d key to delete an item or any other to continue"<<endl;
            cin>>d;
            if(d=='d'){
                //todo
                cout<<"Enter the catagory of item to be deleted"<<endl;
                char cat;
                cin>>cat;
                int ca;
                if(cat=='f'){
                    ca=0;
                }
                else if(cat=='v'){
                ca=1;
                }
                else{
                    ca=2;
                }
                cout<<"Enter the  item to be deleted"<<endl;
                string ite;
                cin>>ite;
                int se=6*ca;
                for(int k=se;k<se+6;k++){
                    if(allProducts[k].shortname()==ite){
                        cart.removeproduct(allProducts[k]);
                    }
                }
            }
            else{
                if(checkout(cart)){
                    break;
                }
            }
            
        }
    }
    return 0;
}