class GasStation:public Building
{
	private:
		double fuelAm=0;
		double plan_x;//needs this coordinates to charge ship only if it is close
		double plan_y;
	public:
		void produce()
		{
			if (status)
			{
				passiveSpend();
				fuelAm+=0.1;//produces fuel,which is not s reourse
			}
		}
		void charge(SpaceShip ship)
		{
			if ((abs(ship.getX()-plan_x)<0.1)and(abs(ship.getY()-plan_y)<0.1))//checks if ship is close
			{
				if (fuelAm>0)
				{
					ship.charge(fuelAm);
					fuelAm=0;
				}
			}
		}
		GasStation(double x,double y)
		{
			con_res="ATM";//Always consumes special resourse
			plan_x=x;
			plan_y=y;
		}
};
