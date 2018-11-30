#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include "../shapes/line.h"
#include "../shapes/circle.h"
#include "../shapes/arc.h"
#include "../shapes/bezier.h"
#include "../shapes/ring.h"
#include "../shapes/track.h"
#include "../shapes/rectangle.h"
#include "../shapes/line_text.h"

using std::vector;
using std::endl;
#define PI 3.1415926
#define EPS 0.0001
namespace circos
{

	class SvgGraph
	{
		std::ostringstream output;
		const std::string file_name;
		int path_index = 0;
		const int background_radius;
		const Color background_color;
		const std::unordered_map<std::string, std::pair<std::string, std::string>>& font_info;//first is png font filepath second is svn font name
	public:
		SvgGraph(const std::unordered_map<std::string, std::pair<std::string, std::string>>& in_font_info,
			string in_file_name, int in_background_radius, Color in_background_color);
			
		SvgGraph& operator<<(const string& input_str);
		SvgGraph& operator<<(int value);
		SvgGraph& operator<<(double value);
		SvgGraph& operator<<(Color color);
		SvgGraph& operator<<(const Point& point);
		void add_to_path(const Line& line);
		SvgGraph& operator<<(const Line& line);
		const std::string& get_font_name(const std::string& input_name)const;

		void add_to_path(const Arc& arc);
		SvgGraph& operator<<( const Arc& arc);

		SvgGraph& operator<<(const Bezier& bezier);
		void add_to_path(const Bezier& bezier);
		SvgGraph& operator<<(const Circle& circle);
		SvgGraph& operator<<(const Rectangle& rect);
		SvgGraph& operator<<(const Ring& ring);
		SvgGraph& operator<<(const Track& track);
		SvgGraph& operator<<(const LineText& line_text);
		~SvgGraph();
	};
}