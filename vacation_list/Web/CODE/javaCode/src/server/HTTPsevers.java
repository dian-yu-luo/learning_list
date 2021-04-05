package server;

import java.io.*;
import java.net.*;
import java.nio.charset.StandardCharsets;


public class HTTPsevers {
    public static void main(String[] args) {
        int port;
        ServerSocket serverSocket;
        try {
            port = Integer.parseInt(args[0]);
        } catch (Exception e) {
            System.out.println("port = 8080(default)");
            port = 8080;
        }

        try {
            serverSocket = new ServerSocket(port);
            System.out.println("正在监听" + serverSocket.getLocalPort());
            while (true) {
                try {
                    final Socket socket = serverSocket.accept();
                    System.out.println("建立了联系" + socket.getInetAddress() + ":" + socket.getPort());
                    service(socket);

                }catch (Exception e){
                    System.out.println("no resource can be call");
                }
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static void service(Socket socket) throws Exception {
        InputStream socketIn = socket.getInputStream();
        Thread.sleep(500);
        int size = socketIn.available();
        byte[] buffer = new byte[size];
        socketIn.read(buffer);
        String request = new String(buffer);
        System.out.println(request);
        int endIndex = request.indexOf("\f\n");
        if (endIndex == -1)
            endIndex = request.length();
        String firshLineofRequest =
                request.substring(0, endIndex);

        String[] parts = firshLineofRequest.split(" ");
        String uri = "";
        if (parts.length >= 2)
            uri = parts[1];

        String contentType;
        if (uri.indexOf("html") != -1 || uri.indexOf("htm") != -1) {
            contentType = "text/html";

        } else if (uri.indexOf("jpg") != -1 || uri.indexOf("jpeg") != -1)
            contentType = "image/jpeg";
        else if (uri.indexOf("gif") != -1)
            contentType = "image/gif";
        else
            contentType = "application/cotet-stream";

        String resopnseFirstLine = "HTTP/1.1 200 OK \r\n";
        String responseHEader = "content-Type:" + contentType + "\r\n\r\n";
        InputStream in =HTTPsevers.class.getResourceAsStream("root/"+uri);
        OutputStream socketOut=socket.getOutputStream();
        socketOut.write(resopnseFirstLine.getBytes(StandardCharsets.UTF_8));
        socketOut.write(responseHEader.getBytes());
        int len=0;
        buffer=new byte[128];
        while ((len=in.read(buffer))!=-1){
            socketOut.write(buffer,0,len);
            Thread.sleep(1000);
            socket.close();
        }
    }
};
