#include <cmath>
#include <ostream>
#include "global_container.h"
#include "colors.h"
using std::ostream;
using std::sin;
using std::cos;
#pragma once
namespace circos
{
	extern double background_radius;
	struct SvgPoint
	{
		double x;
		double y;
		SvgPoint() :x(0), y(0)
		{

		}
		SvgPoint(std::pair<double,double> x_y_point) :x(x_y_point.first), y(x_y_point.second)
		{

		}
		SvgPoint(const SvgPoint& other_point)
		{
			x = other_point.x;
			y = other_point.y;
		}
		SvgPoint(double radius, double angle)
		{
			double dx, dy;
			dx = radius*sin(angle);
			dy = -radius*cos(angle);
			x = dx + background_radius;
			y = dy + background_radius;
		}
		SvgPoint& operator=(const SvgPoint& other_point)
		{
			if (&other_point != this)
			{
				x = other_point.x;
				y = other_point.y;
			}
			return *this;
		}
		friend ostream& operator<<(ostream& in_stream, const SvgPoint& in_point)
		{
			in_stream << in_point.x << "," << in_point.y << " ";
			return in_stream;
		}
	};
	struct SvgLine
	{
		SvgPoint from;
		SvgPoint to;
		double width;
		color line_color;
		double opacity;
		SvgLine() :from(), to(), line_color(), opacity(1)
		{
		
		}
		SvgLine& operator=(const SvgLine& other_line)
		{
			from = other_line.from;
			to = other_line.to;
			width = other_line.width;
			line_color = other_line.line_color;
			opacity = other_line.opacity;
			return *this;
		}
		SvgLine(const SvgPoint& in_from, const SvgPoint& in_to, const color& in_color,double in_width)
			:from(in_from), to(in_to), line_color(in_color), width(in_width)
		{
			opacity = 1;
		}
		friend ostream& operator<<(ostream& in_stream, const SvgLine& in_line)
		{
			in_stream << "<line ";
			in_stream << "x1=\"" << in_line.from.x << "\" y1=\" "<< in_line.from.y << "\" ";
			in_stream << "x2=\"" << in_line.to.x << "\" y2=\"" << in_line.to.y << "\" ";
			in_stream << "stroke=\"" << in_line.line_color << "\" ";
			in_stream << "stroke-width=\"" << in_line.width << "\" ";
			in_stream << "opacity=\"" << in_line.opacity << "\" ";
			in_stream << "/>\n";
			return in_stream;
		}
		int convert_to_path(ostream& in_stream)
		{
			//<path id="textPath" d="M 250 500 A 250,250 0 1 1 250 500.0001"/>
			in_stream << "<path id=\"textPath" << path_index << "\" d=\"M";
			in_stream <<"d=\"M"<< from.x << " " << from.y;
			in_stream << "L" << to.x << " " << to.y;
			in_stream << "\"/>\n";
			path_index++;
			return path_index-1;
		}
	};
	
	
};
