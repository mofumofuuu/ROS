// Generated by gencpp from file learning_communication/DoDisherFeedback.msg
// DO NOT EDIT!


#ifndef LEARNING_COMMUNICATION_MESSAGE_DODISHERFEEDBACK_H
#define LEARNING_COMMUNICATION_MESSAGE_DODISHERFEEDBACK_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace learning_communication
{
template <class ContainerAllocator>
struct DoDisherFeedback_
{
  typedef DoDisherFeedback_<ContainerAllocator> Type;

  DoDisherFeedback_()
    : percent_complete(0.0)  {
    }
  DoDisherFeedback_(const ContainerAllocator& _alloc)
    : percent_complete(0.0)  {
  (void)_alloc;
    }



   typedef float _percent_complete_type;
  _percent_complete_type percent_complete;





  typedef boost::shared_ptr< ::learning_communication::DoDisherFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::learning_communication::DoDisherFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct DoDisherFeedback_

typedef ::learning_communication::DoDisherFeedback_<std::allocator<void> > DoDisherFeedback;

typedef boost::shared_ptr< ::learning_communication::DoDisherFeedback > DoDisherFeedbackPtr;
typedef boost::shared_ptr< ::learning_communication::DoDisherFeedback const> DoDisherFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::learning_communication::DoDisherFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::learning_communication::DoDisherFeedback_<ContainerAllocator1> & lhs, const ::learning_communication::DoDisherFeedback_<ContainerAllocator2> & rhs)
{
  return lhs.percent_complete == rhs.percent_complete;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::learning_communication::DoDisherFeedback_<ContainerAllocator1> & lhs, const ::learning_communication::DoDisherFeedback_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace learning_communication

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learning_communication::DoDisherFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_communication::DoDisherFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_communication::DoDisherFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d342375c60a5a58d3bc32664070a1368";
  }

  static const char* value(const ::learning_communication::DoDisherFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd342375c60a5a58dULL;
  static const uint64_t static_value2 = 0x3bc32664070a1368ULL;
};

template<class ContainerAllocator>
struct DataType< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "learning_communication/DoDisherFeedback";
  }

  static const char* value(const ::learning_communication::DoDisherFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"float32 percent_complete\n"
;
  }

  static const char* value(const ::learning_communication::DoDisherFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.percent_complete);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DoDisherFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::learning_communication::DoDisherFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::learning_communication::DoDisherFeedback_<ContainerAllocator>& v)
  {
    s << indent << "percent_complete: ";
    Printer<float>::stream(s, indent + "  ", v.percent_complete);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LEARNING_COMMUNICATION_MESSAGE_DODISHERFEEDBACK_H
