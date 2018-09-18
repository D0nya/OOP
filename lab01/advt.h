class Advt {
private:
	char *name;
	char *phone_num;
	char *category;
	int price;
public:
	Advt();
	Advt(char*, char*, char*, int);
	Advt(const Advt&);
	~Advt();

	void set_name(char*);
	void set_phonenum(char*)
	void set_category(char*);
	void set_price(int);
	void get_name();
	void get_phonenum();
	void get_category();
	void get_price();
};