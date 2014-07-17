#include "write_entities.h"

void Dxf_write_entities::DxfBegin()
{
	ofstream f("entity.dxf", ios::out);
//Header Section
	f<<0<<endl;
	f<<"SECTION"<<endl;
	f<<2<<endl;
	f<<"ENTITIES"<<endl;

	f.close();
}

void Dxf_write_entities::DxfEnd()
{
	ofstream f("entity.dxf", ios::app);
	
//End of Sequence section
	f<<0<<endl;
	f<<"ENDSEC"<<endl;
	f<<0<<endl;
	f<<"EOF";

	f.close();
}

void Dxf_write_entities::Dxf_draw_point(float x1, float y1, std::string ly)
{
	ofstream f("entity.dxf", ios::app);

	f<<0<<endl;
	f<<"POINT"<<endl;
	f<<8<<endl;	//layer name group code
	f<<ly<<endl;	//layer number

/* **********  Point Coordinates  ********** */

	f<<10<<endl;	//x coord group code
	f<<x1<<endl;
	f<<20<<endl;	//y coord group code
	f<<y1<<endl;
	f<<30<<endl;	//z coord group code
	f<<0.0<<endl;

	f.close();
}

void Dxf_write_entities::Dxf_draw_line(float x1, float y1, float x2, float y2, std::string ly)
{
	ofstream f("entity.dxf", ios::app);

	f<<0<<endl;
	f<<"LINE"<<endl;
	f<<8<<endl;	//layer name group code
	f<<ly<<endl;	//layer number

/* **********  Initial Point Coordinates  ********** */

	f<<10<<endl;	//x coord group code
	f<<x1<<endl;
	f<<20<<endl;	//y coord group code
	f<<y1<<endl;
	f<<30<<endl;	//z coord group code
	f<<0.0<<endl;

/* **********  Final Point Coordinates  ********** */

	f<<11<<endl;	//x coord group code
	f<<x2<<endl;
	f<<21<<endl;	//y coord group code
	f<<y2<<endl;
	f<<31<<endl;	//z coord group code
	f<<0.0<<endl;


	f.close();
}

void Dxf_write_entities::Dxf_draw_circle(float r, float x, float y, std::string ly)
{
	ofstream f("entity.dxf", ios::app);

	f<<0<<endl;
	f<<"CIRCLE"<<endl;
	f<<8<<endl;	//layer name group code
	f<<ly<<endl;	//layer number

/* **********  Center Coordinates  ********** */

	f<<10<<endl;	//x coord group code
	f<<x<<endl;
	f<<20<<endl;	//y coord group code
	f<<y<<endl;
	f<<30<<endl;	//z coord group code
	f<<0.0<<endl;

/* ******************************* */

	f<<40<<endl;	//radious group code
	f<<r<<endl;

	f.close();
}

void Dxf_write_entities::Dxf_draw_rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, std::string ly)
{
	ofstream f("entity.dxf",ios::app);
//first line
	f<<0<<endl;
	f<<"LINE"<<endl;
	f<<8<<endl;
	f<<ly<<endl;
	f<<10<<endl;
	f<<x1<<endl;
	f<<20<<endl;
	f<<y1<<endl;
	f<<30<<endl;
	f<<0.0<<endl;
	f<<11<<endl;
	f<<x2<<endl;
	f<<21<<endl;
	f<<y2<<endl;
	f<<31<<endl;
	f<<0.0<<endl;
//second line
	f<<0<<endl;
	f<<"LINE"<<endl;
	f<<8<<endl;
	f<<ly<<endl;
	f<<10<<endl;
	f<<x2<<endl;
	f<<20<<endl;
	f<<y2<<endl;
	f<<30<<endl;
	f<<0.0<<endl;
	f<<11<<endl;
	f<<x3<<endl;
	f<<21<<endl;
	f<<y3<<endl;
	f<<31<<endl;
	f<<0.0<<endl;
//third line
	f<<0<<endl;
	f<<"LINE"<<endl;
	f<<8<<endl;
	f<<ly<<endl;
	f<<10<<endl;
	f<<x3<<endl;
	f<<20<<endl;
	f<<y3<<endl;
	f<<30<<endl;
	f<<0.0<<endl;
	f<<11<<endl;
	f<<x4<<endl;
	f<<21<<endl;
	f<<y4<<endl;
	f<<31<<endl;
	f<<0.0<<endl;
//fourth line
	f<<0<<endl;
	f<<"LINE"<<endl;
	f<<8<<endl;
	f<<ly<<endl;
	f<<10<<endl;
	f<<x4<<endl;
	f<<20<<endl;
	f<<y4<<endl;
	f<<30<<endl;
	f<<0.0<<endl;
	f<<11<<endl;
	f<<x1<<endl;
	f<<21<<endl;
	f<<y1<<endl;
	f<<31<<endl;
	f<<0.0<<endl;

	f.close();
}

void Dxf_write_entities::Dxf_draw_arc(float x, float y, float r, float S_angle, float E_angle, std::string ly)
		{
	ofstream f("entity.dxf",ios::app);

	f<<0<<endl;
	f<<"ARC"<<endl;
	f<<8<<endl; 
	f<<ly<<endl;

/* **********  Center Coordinates  ********** */

	f<<10<<endl;	//x coord group code
	f<<x<<endl;
	f<<20<<endl;	//y coord group code
	f<<y<<endl;
	f<<30<<endl;	//z coord group code
	f<<0.0<<endl;

/* ******************************* */

	f<<40<<endl;	//radious group code
	f<<r<<endl;
/* ******************************* */

    	f<<50<<endl;    // start angle
    	f<<S_angle<<endl; 
    	f<<51<<endl;    // end angle
	f<<E_angle<<endl;

	f.close();
	}


	void Dxf_write_entities::Dxf_draw_ellipse(  float x, float y, float rxy, float Spart, float Epart,  std::string ly)
			{
	ofstream f("entity.dxf",ios::app);
	
	f<<0<<endl;
	f<<"ELLIPSE"<<endl;
	f<<8<<endl; 
	f<<ly<<endl;
	
	/* **********  Center Coordinates  ********** */
	
	f<<10<<endl;	//x coord group code
	f<<x<<endl;
	f<<20<<endl;	//y coord group code
	f<<y<<endl;
	f<<30<<endl;	//z coord group code
	f<<0.0<<endl;

/* ******************************* */
	f<<11<<endl;	//distance in xy-axis
	f<<rxy<<endl;			
	
	/* ******************************* */
	

	f<<41<<endl; // Start parameter
	f<<Spart<<endl;
	f<<42<<endl;
	f<<Epart<<endl; //End parameter
	
	
	f.close();
}


