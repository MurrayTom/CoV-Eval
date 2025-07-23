```python
import socket
import select
import threading
from datetime import datetime

# Start a more robust server that listens on a specific port, handles incoming connections using non-blocking sockets,
# records connection times, and manages multiple clients simultaneously.
def start_advanced_server(port, max_clients):
    # Create a TCP/IP socket and set it to non-blocking
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setblocking(False)
    
    # Bind the socket to the port
    server_socket.bind(('localhost', port))
    server_socket.listen(max_clients)
    
    # Prepare to handle multiple connections
    inputs = [server_socket]
    client_info = {}
    
    #-copilot next line-
```