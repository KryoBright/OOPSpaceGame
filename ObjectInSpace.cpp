class ObjectInSpace:public ResourseContainer//inherits from ResourseContiner.Still abstract,because function is not overriden
{   //everything is pretty much self explanatory;
	protected:
		double x_coor;
		double y_coor;

	public:
		void setCordinate(double x,double y)
		{
			x_coor=x;
			y_coor=y;
		}
		double getX()
		{
			return x_coor;
		}
		double getY()
		{
			return y_coor;
		}
};
