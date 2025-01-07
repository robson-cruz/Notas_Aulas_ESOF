package publication;

/**
 * Represents a general publication with a title.
 */
public class Publication {
    private String title;

    /**
     * Constructs a Publication with the specified title.
     *
     * @param title the title of the publication
     */
    public Publication(String title) {
        this.title = title;
    }

    /**
     * Gets the full information of the publication.
     *
     * @return a string containing the type, details, and title of the publication
     */
    public final String getInfo() {
        return getType() + getDetails() + title;
    }

    /**
     * Gets the type of the publication.
     *
     * @return the type of the publication
     */
    public String getType() {
        return "Publication";
    }

    /**
     * Gets additional details about the publication.
     *
     * @return a string containing additional details about the publication
     */
    public String getDetails() {
        return ": ";
    }
}
