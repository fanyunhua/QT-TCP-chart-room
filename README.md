#此接口用Json传输数据

Client action : “login”,”send_message”,”send_file”
Client send
{
“action”:“login”,
“user”:”user_name”
}
{
“action”:“send_message”,
“message”:”msg”,
“from_user”:”user_name”,      (ALL_USER)
“to_user”:”user_name”
}




整体逻辑：
客户端直连数据库，登陆成功之后->发送登陆操作 
服务端判断action 进行处理，如果是login操作 将用户名存入队列，用来一对一发送消息，客户端下线后删除队列中的用户名
否则去查用户在不在线，不在线就扔掉数据，回馈客户端对方已下线

Server action :online,offline,group_message,personal_message
{
“action”:”online/offline”,
“user”:”user name”
“online_count”:count(int)
}
{
“action”:”group_message”,
“message”:“XXX”,
“from_user”:”user”
}
{
“action”:”personal_message”,
“status”:”online/offline”,
“from_user”:”user”,
“message”:“XXX”
}

