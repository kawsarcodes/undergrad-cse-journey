/*
Problem(3): Implement an isolated notification layer that retains fallback 
            channel logging protocols via structural super hooks.
Input 
Notification target: SMS System with body payload
Output
Global System Warning: Initializing system connection routing rules.
SMS Output Protocol: Delivering message -> System alert dispatched.
*/

class BaseNotificationChannel {
    public void dispatchAlertMessage(String textBody) {
        System.out.println("Global System Warning: Initializing system connection routing rules.");
    }
}

class SmsNotificationChannel extends BaseNotificationChannel {
    @Override
    public void dispatchAlertMessage(String textBody) {
        super.dispatchAlertMessage(textBody);
        System.out.println("SMS Output Protocol: Delivering message -> " + textBody);
    }
}

public class MethodOverridingSuper {
    public static void main(String[] args) {
        SmsNotificationChannel channel = new SmsNotificationChannel();
        channel.dispatchAlertMessage("System alert dispatched.");
    }
}