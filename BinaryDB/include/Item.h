#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>

class Item {
	private:
		int id;
		int type;
		std::string name;

		virtual std::string pToString() = 0;

	public:
		static const int DBD_STRING = 1;
		static const int DBD_INT = 2;
		static const int DBD_DOUBLE = 3;

		Item (int id, std::string name, int type) {
			this->id = id;
			this->name = name;
			this->type = type;
		}
		virtual ~Item () {}

		int getId () { return this->id; }
		void setId (int id) { this->id = id; };

		int getType () { return this->type; }
		
		std::string getName () { return this->name; }
		void setName (std::string name) { this->name = name; }

		std::string getTypeAsString () {
			switch(this->type) {
				case DBD_STRING:
					return "DBD_STRING";
				case DBD_INT:
					return "DBD_INT";
				case DBD_DOUBLE:
					return "DBD_DOUBLE";
				default:
					return NULL;
			}
		}

		std::string toString () { 
			return "Id: " + std::to_string(this->id) + "\nType: " + std::to_string(this->type) + "\nTypeAsString: " + this->getTypeAsString() + "\nName: " + this->name + "\n" + this->pToString(); 
		}
};

#endif // _ITEM_H_
