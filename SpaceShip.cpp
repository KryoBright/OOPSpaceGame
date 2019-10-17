class SpaceShip:public ObjectInSpace//inherits from ObjectInSpace
{
	private:
		double fuel=100;
		long id;
		void abst()
		{
			//not abstract anymore
		}
	public:
		//self explanatory
		SpaceShip(long num)
		{
			id=num;
		}
		bool moveTo(double x,double y)
		{
			if (fuel>=sqrt((x_coor-x)*(x_coor-x)+(y_coor-y)*(y_coor-y)))
			{
				fuel-=sqrt((x_coor-x)*(x_coor-x)+(y_coor-y)*(y_coor-y));
				x_coor=x;
				y_coor=y;
				return true;
			}
			else
			{
				cout<<"Not enough fuel for ship "<<id<<" to get to"<<x<<" "<<y<<endl;
				return false;
			}
		}
		void charge(double amount)
		{
			fuel+=amount;
		}

};

