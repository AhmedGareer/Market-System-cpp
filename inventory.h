#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <fstream>
#include "product.h"
using namespace std;

class inventory
{
public:
    product* read_products = new product;
    product* write_products = new product;
};

#endif // INVENTORY_H
