
#include <bits/stdc++.h>

using namespace std;

struct Product
{
  int id;
  string name;
  double price;
};

struct CartItem
{
  Product product;
  int quantity;
};

class ShoppingCart
{
private:
  unordered_map < int, Product > products;
    list < CartItem > cart;		// Using list instead of vector for cart items
  double totalPrice = 0.0;

public:
  void addProduct (const Product & product)
  {
	products[product.id] = product;
  }

  void addToCart (int productId, int quantity)
  {
	if (products.find (productId) != products.end ())
	  {
		bool found = false;
	  for (auto & item:cart)
		  {
			if (item.product.id == productId)
			  {
				item.quantity += quantity;
				found = true;
				break;
			  }
		  }
		if (!found)
		  {
			cart.push_back (
							 {
							 products[productId], quantity}
			);
		  }
		totalPrice += products[productId].price * quantity;
		cout << "Product added to cart.\n";
	  }
	else
	  {
		cout << "Product ID not found.\n";
	  }
  }

  void removeFromCart (int productId, int quantity)
  {
	for (auto it = cart.begin (); it != cart.end (); ++it)
	  {
		if (it->product.id == productId)
		  {
			if (it->quantity > quantity)
			  {
				it->quantity -= quantity;
				totalPrice -= it->product.price * quantity;
			  }
			else
			  {
				totalPrice -= it->product.price * it->quantity;
				cart.erase (it);
			  }
			cout << "Product removed from cart.\n";
			return;
		  }
	  }
	cout << "Product not found in cart.\n";
  }

  void searchProduct (int productId)
  {
	if (products.find (productId) != products.end ())
	  {
		Product p = products[productId];
		cout << "Product ID: " << p.id << ", Name: " << p.
		  name << ", Price: $" << fixed << setprecision (2) << p.
		  price << '\n';
	  }
	else
	  {
		cout << "Product ID not found.\n";
	  }
  }

  void viewCart ()
  {
	if (cart.empty ())
	  {
		cout << "Cart is empty.\n";
		return;
	  }
	cout << "\n\nCart items:\n";
	cout << "Product ID      " << "Name        " << "Quantity     " <<
	  "Total Price             " << '\n';
  for (const auto & item:cart)
	  {
		cout << item.product.id << "               " << item.product.
		  name << "       " << item.
		  quantity << "           $" << fixed << setprecision (2) << item.
		  product.price * item.quantity << '\n';
	  }
	cout << "\nTotal Cart Price: $" << fixed << setprecision (2) << totalPrice
	  << '\n';
  }
  void viewProducts ()
  {
	cout << "\n\nAvailable products:\n";
	cout << "  Product ID      " << "Name        " << "Price             " <<
	  '\n';
  for (const auto & pair:products)
	  {
		cout << "  " << pair.first << "               " << pair.second.
		  name << "      $" << pair.second.price << "\n";
	  }
  }
  // void viewCart() {
  //     if (cart.empty()) {
  //         cout << "Cart is empty.\n";
  //         return;
  //     }
  //     cout << "Cart contents:\n";
  //     for (const auto& item : cart) {
  //         cout << item.product.id << " - " << item.product.name << " - $" << item.product.price << " x " << item.quantity << "\n";
  //     }
  //     cout << "Total Price: $" << totalPrice << "\n";
  // }

  void checkout ()
  {
	int option;
	while (true)
	  {
		cout <<
		  "Checkout options:\n1. Successful\n2. Failed\nSelect an option: ";
		cin >> option;
		if (cin.fail () || (option != 1 && option != 2))
		  {
			cin.clear ();
			cin.ignore (numeric_limits < streamsize >::max (), '\n');
			cout << "Invalid option. Try again.\n";
		  }
		else
		  {
			break;
		  }
	  }

	if (option == 1)
	  {
		cout << "Checkout Successful!\n";
		viewCart ();
		cout << "Thank you for your purchase!\n";
		cart.clear ();
		totalPrice = 0.0;
	  }
	else
	  {
		cout << "Checkout Failed. Returning to checkout process.\n";
	  }
  }
};

int
main ()
{
  ShoppingCart cart;
  cart.addProduct (
					{
					1, "Apple", 1.50});
  cart.addProduct (
					{
					2, "Banana", 0.75});
  cart.addProduct (
					{
					3, "Orange", 1.25});

  int choice, id, quantity;

  cout <<
	"  -----------------------------------------Welcome TO Cart Management System------------------------------\n\n";
  while (true)
	{
	  cout <<
		"\n1. View Products \n2. Add Product to Cart\n3. Remove Product from Cart\n4. Search Product\n5. View Cart\n6. Checkout\n7. Exit\nSelect an option: ";
	  cin >> choice;

	  switch (choice)
		{
		case 1:
		  cart.viewProducts ();
		  break;
		case 2:
		  cout << "Enter product ID to add: ";
		  cin >> id;
		  cout << "Enter quantity: ";
		  cin >> quantity;
		  cart.addToCart (id, quantity);
		  break;
		case 3:
		  cout << "Enter product ID to remove: ";
		  cin >> id;
		  cout << "Enter quantity: ";
		  cin >> quantity;
		  cart.removeFromCart (id, quantity);
		  break;
		case 4:
		  cout << "Enter product ID to search: ";
		  cin >> id;
		  cart.searchProduct (id);
		  break;
		case 5:
		  cart.viewCart ();
		  break;
		case 6:
		  cart.checkout ();
		  break;
		case 7:
		  return 0;
		default:
		  cout << "Invalid option. Try again.\n";
		}
	}

  return 0;
}

