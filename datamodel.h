#include <string>
#include <unordered_map>
using namespace std;
class Item;
class cart;
class Product{
    int id;
    string name;
    int price;
public:
    Product(){

    }
    Product(int u_id,string name,int price){
        id=u_id;
        this->name=name;
        this->price=price;
    }
    string getDisplatName(){
        return name + " :Rs "+to_string(price)+"\n";
    }
    string shortname(){
        return  name.substr(0,1);
    }
    friend class Item;
    friend class Cart;

};
class Item{
    Product product;
    int quantity;
    public:
    Item(){

    }
    Item(Product p,int q):product(p), quantity(q){}
    int getprice(){
        return quantity*product.price;
    }
    string getiteminfo(){
        return to_string(quantity)+" x "+product.name +" Rs "+to_string(quantity*product.price)+"\n";
    }
    void addquantity(int q){
        this->quantity+=q;
    }
    void makequantity(int q){
        this->quantity=q;
    }
    friend class Cart;
};
class Cart{
    unordered_map<int,Item> items;
    public:
    void addProduct(Product product, int q){
        if(items.count(product.id)==0){
            Item newItem(product,q);
            items[product.id] = newItem;
        }
        else{
            items[product.id].addquantity(q);
        }
    }
    int getTotal(){
        int total=0;
        for(auto itempair:items){
            auto item=itempair.second;
            total+=item.getprice();
        }
        return total;

    }
    string viewcart(){
        if(items.empty()){
            return "Cart is empty\n";
        }
        string itemlist;
        int card_total=getTotal();
        for(auto itemPair:items){
            auto item=itemPair.second;
            itemlist.append(item.getiteminfo());
        }
        return itemlist+"\n Total Amount : Rs "+ to_string(card_total)+"\n";
    }
    bool isempty(){
        return items.empty();
    }
    void removeproduct(Product product){
        if(items.count(product.id)==0){
            cout<<"Invalid!"<<endl;
        }
        else{
            items[product.id].makequantity(0);
            items.erase(product.id);
        }
    }
    
    

};