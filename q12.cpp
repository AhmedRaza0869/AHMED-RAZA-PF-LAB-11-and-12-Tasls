#include <stdio.h>
#include <string.h>

struct Cust {
    char name[50];
    char city[30];
    char phone[15];
};

struct Prod {
    char name[50];
    float price;
    int qty;
};

struct Order {
    int id;
    struct Cust cust;
    struct Prod prod;
    float total;
};

int main() {
    int n;
    
    printf("Enter number of orders: ");
    scanf("%d", &n);
    
    struct Order orders[n];
    
    for(int i = 0; i < n; i++) {
        printf("\n=== Order %d ===\n", i + 1);
        
        printf("Order ID: ");
        scanf("%d", &orders[i].id);
        
        printf("Customer Name: ");
        scanf(" %[^\n]", orders[i].cust.name);
        printf("City: ");
        scanf(" %[^\n]", orders[i].cust.city);
        printf("Phone: ");
        scanf(" %[^\n]", orders[i].cust.phone);
        
        printf("Product Name: ");
        scanf(" %[^\n]", orders[i].prod.name);
        printf("Unit Price: ");
        scanf("%f", &orders[i].prod.price);
        printf("Quantity: ");
        scanf("%d", &orders[i].prod.qty);
        
        orders[i].total = orders[i].prod.price * orders[i].prod.qty;
    }
    
    printf("\n=== ORDER SUMMARY ===\n");
    printf("ID\tCustomer\tCity\t\tProduct\t\tTotal\n");
    printf("------------------------------------------------------------------------\n");
    
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%s\t$%.2f\n", 
               orders[i].id,
               orders[i].cust.name,
               orders[i].cust.city,
               orders[i].prod.name,
               orders[i].total);
    }
    
    return 0;
}
