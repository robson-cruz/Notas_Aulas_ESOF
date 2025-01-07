package publication;

/**
 * Represents an announcement publication with an expiration period.
 */
public class Announcement extends Publication {
    private int daysToExpire;

    /**
     * Constructs an Announcement with the specified title and days to expire.
     *
     * @param title        the title of the announcement
     * @param daysToExpire the number of days until the announcement expires
     */
    public Announcement(String title, int daysToExpire) {
        super(title);
        this.daysToExpire = daysToExpire;
    }

    /**
     * Gets the type of the publication.
     *
     * @return "Announcement"
     */
    @Override
    public String getType() {
        return "Announcement";
    }

    /**
     * Gets additional details about the announcement.
     *
     * @return a string containing the number of days to expire
     */
    @Override
    public String getDetails() {
        return " (days to expire - " + this.daysToExpire + "):";
    }
}
