#ifndef POLYGON_BASE_REGULAR_POLYGON_HPP
#define POLYGON_BASE_REGULAR_POLYGON_HPP

namespace polygon_base
{
  class RegularPolygon
  {
    public:
      virtual void initialize(double side_length) = 0;
      virtual double area() = 0;
      virtual ~RegularPolygon(){}

    protected:
        // pluginlib ဖြစ်ရန် parameter  မပါတဲ့ constructor  လိုအပ်တယ်။ 
        // အဲတော့ parameter တွေလိုအပ်ရင် initialize method ကို သုံဂမယ်။ 
      RegularPolygon(){}
  };
}  // namespace polygon_base

#endif  // POLYGON_BASE_REGULAR_POLYGON_HPP