
/**
 * @file ClientConnection.java
 * @brief Handles the client-side connection to the server.
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * @brief ClientConnection class that handles the client-side connection to the server.
 */
public class ClientConnection {
    private Socket socket;
    private PrintWriter out;
    private BufferedReader in;

    /**
     * @brief Constructor for the ClientConnection class.
     * @param host The host to connect to.
     * @param port The port to connect to.
     */
    public ClientConnection(String host, int port) {
        try {
            socket = new Socket(host, port);
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * @brief Sends a message to the server.
     * @param message The message to send.
     */
    public void sendMessage(String message) {
        out.println(message);
    }

    /**
     * @brief Receives a message from the server.
     * @return The message received.
     */
    public String receiveMessage() {
        try {
            return in.readLine();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * @brief Closes the connection to the server.
     */
    public void close() {
        try {
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}