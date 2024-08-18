HTTP报文由两部分组成：请求报文和响应报文。它们都包含一些共同的字段和特定于请求或响应的字段。

    共同字段：
        Start Line（起始行）：包括请求报文的请求行和响应报文的状态行，描述了请求或响应的基本信息。
        Headers（头部字段）：包含一系列键值对，描述了请求或响应的各种属性和元数据信息。
        Body（消息体）：可选字段，包含请求或响应的具体数据内容。

    请求报文字段：
        Method（方法）：请求使用的方法，如GET、POST、PUT等。
        Request URL（请求URL）：请求的资源路径。
        Request Headers（请求头部字段）：描述请求的各种属性和要求，如User-Agent、Content-Type等。
        Request Body（请求消息体）：可选字段，包含请求的具体数据内容。

    响应报文字段：
        Status Code（状态码）：服务器对请求的处理结果状态码，如200表示成功，404表示未找到等。
        Status Message（状态消息）：状态码对应的描述信息。
        Response Headers（响应头部字段）：描述响应的各种属性和元数据信息，如Server、Content-Type等。
        Response Body（响应消息体）：可选字段，包含响应的具体数据内容。

常见的HTTP头部字段包括：

    Content-Type：指定响应或请求的媒体类型，如text/html、application/json等。
    Content-Length：指定消息体的长度。
    Date：指定报文的创建时间。
    Server：指定服务器软件名称和版本号。
    User-Agent：指定发送请求的用户代理（浏览器、客户端等）信息。
    Cookie：包含客户端的Cookie信息。
    Set-Cookie：设置服务器发送的Cookie信息。

除了上述字段，还有许多其他的HTTP头部字段，用于传递更多的请求和响应信息。具体使用哪些字段取决于实际的需求和场景。