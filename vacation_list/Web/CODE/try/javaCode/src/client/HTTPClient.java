package client;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.*;

public class HTTPClient {
    public static void main(String[] args) {
        String uri = "index.htm";
        if (args.length != 0) {
            uri = args[0];
        }
        doGet("localhost", 8080, uri);

    }

    public static void doGet(String host, int port,
                             String uri) {
        Socket socket = null;
        try {
            socket = new Socket(host, port);
        } catch (Exception e) {
            e.printStackTrace();
        }


        try {
            StringBuffer sb = new StringBuffer("get" +
                    uri + "http/1.1");
            sb.append("accepyt");
            OutputStream socketOut = socket.getOutputStream();
            socketOut.write(sb.toString().getBytes());
            Thread.sleep(2000);
            InputStream sockerIn = socket.getInputStream();
            int size = sockerIn.available();
            byte[] buffer = new byte[size];
            sockerIn.read(buffer);
            System.out.println(new String(buffer));

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                socket.close();

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
