package publication;

/**
 * Represents an article publication with an author.
 */
public class Article extends Publication {
    private String author;

    /**
     * Constructs an Article with the specified title and author.
     *
     * @param title  the title of the article
     * @param author the author of the article
     */
    public Article(String title, String author) {
        super(title);
        this.author = author;
    }

    /**
     * Gets the type of the publication.
     *
     * @return "Article"
     */
    @Override
    public String getType() {
        return "Article";
    }

    /**
     * Gets additional details about the article.
     *
     * @return a string containing the author of the article
     */
    @Override
    public String getDetails() {
        return " (author - " + this.author + "): ";
    }
}
