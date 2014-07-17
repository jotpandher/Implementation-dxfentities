#ifndef WRITE_ENTITIES_H
#define WRITE_ENTITIES_H

#include <fstream>
#include <sstream>
#include <string>

using  namespace std;

#include <libdxfrw0/drw_interface.h>
#include <libdxfrw0/libdxfrw.h>
#include "dxfrw_intf.h"

class Dxf_write_entities :public DRW_InterfaceImpl {
public:
	void DxfBegin();
	void Dxf_draw_point(float, float, std::string);
	void Dxf_draw_line(float, float, float, float, std::string);
	void Dxf_draw_rectangle(float, float, float, float, float, float, float, float, std::string);
	void Dxf_draw_circle(float, float, float, std::string);
	void Dxf_draw_arc(float, float, float, float, float, std::string);
	void Dxf_draw_ellipse( float, float, float, float, float,  std::string);
	void DxfEnd();
};

#endif // WRITE_ENTITIES_H
