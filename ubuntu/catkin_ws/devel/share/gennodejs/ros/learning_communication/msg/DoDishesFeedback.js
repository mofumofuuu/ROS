// Auto-generated. Do not edit!

// (in-package learning_communication.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class DoDishesFeedback {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.percent_complete = null;
    }
    else {
      if (initObj.hasOwnProperty('percent_complete')) {
        this.percent_complete = initObj.percent_complete
      }
      else {
        this.percent_complete = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DoDishesFeedback
    // Serialize message field [percent_complete]
    bufferOffset = _serializer.float32(obj.percent_complete, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DoDishesFeedback
    let len;
    let data = new DoDishesFeedback(null);
    // Deserialize message field [percent_complete]
    data.percent_complete = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'learning_communication/DoDishesFeedback';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd342375c60a5a58d3bc32664070a1368';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    float32 percent_complete
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DoDishesFeedback(null);
    if (msg.percent_complete !== undefined) {
      resolved.percent_complete = msg.percent_complete;
    }
    else {
      resolved.percent_complete = 0.0
    }

    return resolved;
    }
};

module.exports = DoDishesFeedback;
