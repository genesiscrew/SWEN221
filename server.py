import socket
import select
import sqlite3


def run_server():
    """
    Start a server to facilitate the chat between clients.
    The server uses a single socket to accept incoming connections
    which are then added to a list (socket_list) and are listened to
    to recieve incoming messages. Messages are then stored in a database
    and are transmitted back out to the clients.
    """

    # Define where the server is running. 127.0.0.1 is the loopback address,
    # meaning it is running on the local machine.
    host = "127.0.0.1"
    port = 5003
    dictionary = {}
    default = {}
    nickName = ""
    # Create a socket for the server to listen for connecting clients
    server_socket = socket.socket()
    server_socket.bind((host, port))
    server_socket.listen(10)

    # Create a list to manage all of the sockets
    socket_list = []
    # Add the server socket to this list
    socket_list.append(server_socket)
    conn = sqlite3.connect('server.db')
    c = conn.cursor()
    c.execute('CREATE TABLE if not exists user_rooms (room, user, socket)')
   



    # Start listening for input from both the server socket and the clients
    while True:

        # Monitor all of the sockets in socket_list until something happens
        ready_to_read, ready_to_write, in_error = select.select(socket_list, socket_list, [], 0)

        # When something happens, check each of the ready_to_read sockets
        for sock in ready_to_read:
            # A new connection request recieved
            if sock == server_socket:
                # Accept the new socket request
                sockfd, addr = server_socket.accept()
                # Add the socket to the list of sockets to monitor
                socket_list.append(sockfd)
                # Log what has happened on the server
                print ("Client (%s, %s) connected" % (addr[0],addr[1]))
                c.execute('INSERT INTO user_rooms (room, user, socket) values (\'%s\',\'%s\',\'%s\')' % ('GLOBAL', '', addr[1]))
             

            # A message from a client has been recieved
            else:
                
                # YOUR CODE HERE
                # Extract the data from the socket and iterate over the socket_list
                # to send the data to each of the connected clients.
               # Data recieved from client, process it
                #try:
                    #In Windows, sometimes when a TCP program closes abruptly,
                    # a "Connection reset by peer" exception will be thrown
                data = sock.recv(1024)
                data= data.decode()
                sockzz = sock
                if sockzz not in dictionary:
                    dictionary[''] = sockzz
              
                    # echo back the client message
              
                # server sends message received to all clients connected in a group
                
                for row in c.execute('SELECT room FROM user_rooms where socket = \'%s\'' %  sockzz.getpeername()[1]):
                        roomFound =  ' '.join(['##', row[0]])
                        
                        
                        for row in c.execute('SELECT socket FROM user_rooms where room = \'%s\'' % roomFound.split(' ')[1] ):
                            logger = row[0]
                            for sockky in ready_to_write:
                                if sockky.getpeername()[1] == int(logger) and  sock != server_socket and "/NICK" not in data and "/JOIN" not in data and "/WHO" not in data and "/MSG" not in data and "#!#" not in data:              
                                    roomFound = roomFound.split(" ")[0:2]
                                    roomFound = "".join(roomFound) 
                                    data =  ' '.join([roomFound, data])
                                    sockky.send(data.encode())
                                    roomFound = ''
                        
                # set a nickname for users
                if "/NICK" in data:
                    command = data.split(" ")[0]
                    nickName = data.split(" ")[1].strip()
                    if nickName not in dictionary:
                        dictionary[nickName]=sock
                        c.execute('UPDATE user_rooms set user = \'%s\' where socket = \'%s\'' % (nickName, sockzz.getpeername()[1]))      
                    elif nickName in dictionary:
                        sockzz.send("nickname already exists".encode())
                # once a user joins a room, he can only communicate with users in a group
                # if a group already exists, they join that group, otherwise a new group is created
                elif "/JOIN" in data:
                    roomName = data.split(" ")[1].strip()
                    c.execute('UPDATE user_rooms set room = \'%s\' where socket = \'%s\'' % (roomName, sockzz.getpeername()[1]))
                  
                # tells the user who are with him in the room        
                elif "/WHO" in data:    
                    bla = ""
                    for row in c.execute('SELECT room FROM user_rooms where socket = \'%s\'' %  sockzz.getpeername()[1]):
                        roomFound = row[0]
                    for row in c.execute('SELECT user FROM user_rooms where room = \'%s\'' % roomFound):
                        bla = bla+"\n" + row[0]
                    sockzz.send(bla.encode())
                # enables the user to message only to specific user 
                elif "/MSG" in data:
                    socket666 = data.split(" ")[1]
                    socket666 = socket666.strip()
                    messg = data.split(" ")[2:]
                    messg = " ".join(messg)          
                    roomFound = ""
                    if socket666 in dictionary.keys():
                        for row in c.execute('SELECT socket FROM user_rooms where user = \'%s\'' % socket666 ):
                            logger = row[0]
                            print(logger)
                            for sockkkk in ready_to_write:
                                print(sockky.getpeername()[1])      
                                if sockkkk.getpeername()[1] == int(logger):
                                    
                                    messg =  ' '.join([roomFound, messg])
                                    messg = messg.encode()
                                    sockkkk.send(messg)
                    else:
                         sockzz.send("username does not exist".encode())
                        
                           
                    
               
                        
if __name__ == '__main__':
    run_server()
