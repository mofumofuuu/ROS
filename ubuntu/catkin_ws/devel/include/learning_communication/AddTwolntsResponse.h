// Generated by gencpp from file learning_communication/AddTwolntsResponse.msg
// DO NOT EDIT!


#ifndef LEARNING_COMMUNICATION_MESSAGE_ADDTWOLNTSRESPONSE_H
#define LEARNING_COMMUNICATION_MESSAGE_ADDTWOLNTSRESPONSE_H


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
struct AddTwolntsResponse_
{
  typedef AddTwolntsResponse_<ContainerAllocator> Type;

  AddTwolntsResponse_()
    : sum(0)  {
    }
  AddTwolntsResponse_(const ContainerAllocator& _alloc)
    : sum(0)  {
  (void)_alloc;
    }



   typedef int64_t _sum_type;
  _sum_type sum;





  typedef boost::shared_ptr< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> const> ConstPtr;

}; // struct AddTwolntsResponse_

typedef ::learning_communication::AddTwolntsResponse_<std::allocator<void> > AddTwolntsResponse;

typedef boost::shared_ptr< ::learning_communication::AddTwolntsResponse > AddTwolntsResponsePtr;
typedef boost::shared_ptr< ::learning_communication::AddTwolntsResponse const> AddTwolntsResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::learning_communication::AddTwolntsResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::learning_communication::AddTwolntsResponse_<ContainerAllocator1> & lhs, const ::learning_communication::AddTwolntsResponse_<ContainerAllocator2> & rhs)
{
  return lhs.sum == rhs.sum;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::learning_communication::AddTwolntsResponse_<ContainerAllocator1> & lhs, const ::learning_communication::AddTwolntsResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace learning_communication

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b88405221c77b1878a3cbbfff53428d7";
  }

  static const char* value(const ::learning_communication::AddTwolntsResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb88405221c77b187ULL;
  static const uint64_t static_value2 = 0x8a3cbbfff53428d7ULL;
};

template<class ContainerAllocator>
struct DataType< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "learning_communication/AddTwolntsResponse";
  }

  static const char* value(const ::learning_communication::AddTwolntsResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 sum \n"
;
  }

  static const char* value(const ::learning_communication::AddTwolntsResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sum);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddTwolntsResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::learning_communication::AddTwolntsResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::learning_communication::AddTwolntsResponse_<ContainerAllocator>& v)
  {
    s << indent << "sum: ";
    Printer<int64_t>::stream(s, indent + "  ", v.sum);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LEARNING_COMMUNICATION_MESSAGE_ADDTWOLNTSRESPONSE_H
