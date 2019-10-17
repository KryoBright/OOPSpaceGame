class Planet:public ObjectInSpace
{
	private:
		vector<Colony>colonies;
	public:
		string name;//TODO:move to private
		bool colonize(SpaceShip ship )//colonizes planet
		{
			if ((ship.getAmount("Human")>100)and(ship.getAmount("Iron")>100)and(ship.getAmount("Liquid")>100))
			{
				if (ship.moveTo(x_coor,y_coor))
				{
					Colony newCol;
					newCol.par=this;
					colonies.push_back(newCol);
					cout<<"Colony created!"<<endl;
					ship.takeRes("Human",100);
					ship.takeRes("Iron",100);
					ship.takeRes("Liquid",100);
					return true;
				}
			}
			cout<<"Colonization failed!";
			return false;

		}

		Planet(string Name)//fills planet with resourse
		{
			name=Name;
			Resourse resTmp1("Iron",rand()%20000,rand()%200);
			store(resTmp1);
			Resourse resTmp2("Liquid",rand()%20000,rand()%200);
			store(resTmp2);
			Resourse resTmp3("ATM",rand()%20000,rand()%200);
			store(resTmp3);
		}

		void gameCycle()//imitates time passage
		{
			long i=0;
			while (i<colonies.size())
			{
				colonies[i].gameCycle();
				i++;
			}
		}
};

