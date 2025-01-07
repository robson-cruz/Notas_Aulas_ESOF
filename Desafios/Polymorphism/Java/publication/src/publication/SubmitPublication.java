package publication;

/**
 * Utility class to parse input data and create appropriate Publication objects.
 */
public class SubmitPublication {
    /**
     * Parses the input string to create the appropriate Publication object and prints its information.
     *
     * @param data the input string in the format "type;title;additional_info"
     *             where type can be "publication", "newspaper", "article", or "announcement"
     */
    public static void submitData(String data) {
        String[] arr = data.split(";");
        String type = arr[0].trim().toLowerCase();

        Publication publication;

        switch (type) {
            case "publication":
                publication = new Publication(arr[1].trim());
                break;
            case "newspaper":
                publication = new Newspaper(arr[1].trim(), arr[2].trim());
                break;
            case "article":
                publication = new Article(arr[1].trim(), arr[2].trim());
                break;
            case "announcement":
                publication = new Announcement(arr[1].trim(), Integer.parseInt(arr[2].trim()));
                break;
            default:
                System.out.println("Invalid publication type");
                return;
        }

        System.out.println(publication.getInfo());

    }
}
