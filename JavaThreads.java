// JavaThreads.java
// See https://github.com/fordsfords/learning_java

import java.util.*;

class JavaThreads {

  public static void main(String[] args) throws Exception {
    // The body of the program is in the "run" method.
    JavaThreads application = new JavaThreads();
    application.run(args);
  }  // main

  private void run(String[] args) {
    System.out.println("main: Starting");
    MyThingie thingie = new MyThingie(2);
    thingie.start();
    System.out.println("main: Sleeping 4.1 seconds");
    try { Thread.sleep(4100); } catch (Exception e) {}
    System.out.println("main: Terminating");
    thingie.terminate();
    System.out.println("main: Done");
  }  // run
} // JavaThreads


class MyThingie implements Runnable {
  private Thread thisThread;
  private int printIntervalSec;
  private boolean running;

  public MyThingie() {
    this(1);  // default print interval.
  }

  public MyThingie(int printIntervalSec) {
    this.printIntervalSec = printIntervalSec;
    thisThread = null;
    running = false;
  }

  public void start() {
    running = true;
    thisThread = new Thread(this);
    thisThread.start();
  }

  public void terminate() {
    if (running) {
      running = false;
      try {
        thisThread.join();
      } catch (Exception e) {}
    }
  }  // terminate

  public void run() {
    int secsSinceLastPrint = 0;
    while (running) {
      if (secsSinceLastPrint >= printIntervalSec) {
        System.out.println("MyThingie: Hi");
        secsSinceLastPrint = 0;
      }
      try { Thread.sleep(1000); } catch (Exception e) {}
      secsSinceLastPrint++;
    }  // while running
    System.out.println("MyThingie: Bye");
  }  // run
} // MyThingie
