package publication;

/**
 * Represents a newspaper publication with a source.
 */
public class Newspaper extends Publication {
    private String source;

    /**
     * Constructs a Newspaper with the specified title and source.
     *
     * @param title  the title of the newspaper
     * @param source the source of the newspaper
     */
    public Newspaper(String title, String source) {
        super(title);
        this.source = source;
    }

    /**
     * Gets the type of the publication.
     *
     * @return "Newspaper"
     */
    @Override
    public String getType() {
        return "Newspaper";
    }

    /**
     * Gets additional details about the newspaper.
     *
     * @return a string containing the source of the newspaper
     */
    @Override
    public String getDetails() {
        return " (source - " + this.source + "): ";
    }
}
