; Auto-generated. Do not edit!


(cl:in-package learning_communication-msg)


;//! \htmlinclude DoDisherResult.msg.html

(cl:defclass <DoDisherResult> (roslisp-msg-protocol:ros-message)
  ((total_dishes_cleaned
    :reader total_dishes_cleaned
    :initarg :total_dishes_cleaned
    :type cl:integer
    :initform 0))
)

(cl:defclass DoDisherResult (<DoDisherResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DoDisherResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DoDisherResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name learning_communication-msg:<DoDisherResult> is deprecated: use learning_communication-msg:DoDisherResult instead.")))

(cl:ensure-generic-function 'total_dishes_cleaned-val :lambda-list '(m))
(cl:defmethod total_dishes_cleaned-val ((m <DoDisherResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader learning_communication-msg:total_dishes_cleaned-val is deprecated.  Use learning_communication-msg:total_dishes_cleaned instead.")
  (total_dishes_cleaned m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DoDisherResult>) ostream)
  "Serializes a message object of type '<DoDisherResult>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'total_dishes_cleaned)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DoDisherResult>) istream)
  "Deserializes a message object of type '<DoDisherResult>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'total_dishes_cleaned)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DoDisherResult>)))
  "Returns string type for a message object of type '<DoDisherResult>"
  "learning_communication/DoDisherResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DoDisherResult)))
  "Returns string type for a message object of type 'DoDisherResult"
  "learning_communication/DoDisherResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DoDisherResult>)))
  "Returns md5sum for a message object of type '<DoDisherResult>"
  "58faa44dda59c6545bea63ff57491cbe")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DoDisherResult)))
  "Returns md5sum for a message object of type 'DoDisherResult"
  "58faa44dda59c6545bea63ff57491cbe")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DoDisherResult>)))
  "Returns full string definition for message of type '<DoDisherResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%uint32 total_dishes_cleaned~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DoDisherResult)))
  "Returns full string definition for message of type 'DoDisherResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%uint32 total_dishes_cleaned~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DoDisherResult>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DoDisherResult>))
  "Converts a ROS message object to a list"
  (cl:list 'DoDisherResult
    (cl:cons ':total_dishes_cleaned (total_dishes_cleaned msg))
))
