

---

# Simple HTTP Server using Winsock in C++

This is a simple HTTP server implementation in C++ using the Winsock library. It listens on `127.0.0.1` (localhost) on port `8080` and responds with a basic HTML page when a client connects.

## Prerequisites

- Windows operating system.
- Visual Studio or another C++ compiler.
- Basic understanding of C++ programming and networking concepts.

## How to Use

1. Clone this repository or copy the code from `main.cpp` into your project.

2. Open the project in Visual Studio or compile the `main.cpp` file using your preferred C++ compiler.

3. Run the compiled executable.

4. Open a web browser and navigate to `http://127.0.0.1:8080`. You should see a simple HTML page with the message "SERVER SUCCESSFULLY CREATED: HELLO :)".

## Code Explanation

- The code begins by including necessary headers and defining preprocessor directives.

- It initializes Winsock using `WSAStartup`.

- Creates a socket using `socket` function.

- Binds the socket to `127.0.0.1:8080` using `bind`.

- Starts listening for incoming connections using `listen`.

- Enters a loop to accept incoming connections using `accept`.

- Reads the client's request using `recv`.

- Constructs an HTTP response with status code `200 OK` and sends it back to the client using `send`.

- Closes the client socket using `closesocket`.

- The loop continues to accept new connections until the server is terminated.

- Finally, it cleans up Winsock resources using `closesocket` and `WSACleanup`.

## Notes

- This is a basic HTTP server implementation and lacks many features found in production-grade servers, such as concurrency, error handling, and security measures.

- It's intended for educational purposes and should not be used in production environments without significant enhancements.

---

