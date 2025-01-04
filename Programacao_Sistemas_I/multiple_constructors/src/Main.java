public class Main {
    public static void main(String[] args) {
        Robot defaultRobot = new Robot();
        System.out.println("Name: " + defaultRobot.name);
        System.out.println("Model: " + defaultRobot.model);
        System.out.println("Life Time: " + defaultRobot.lifeTime);

        Robot ndr114 = new Robot("NDR", "NDR-114");
        System.out.println("Name: " + ndr114.name);
        System.out.println("Model: " + ndr114.model);
        System.out.println("Model: " + ndr114.lifeTime);

    }
}