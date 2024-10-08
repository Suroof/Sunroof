package com.project.template.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;

import javax.persistence.Id;

public class Books extends BaseEntity {

    @Id
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    private String title;
    private String author;
    private String published_date;
    private String link;
    private String authorLink;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getPublished_date() {
        return published_date;
    }

    public void setPublished_date(String published_date) {
        this.published_date = published_date;
    }

    public String getLink() {return link;}

    public void setLink(String link) {this.link = link;}

    public String getAuthorLink() {return authorLink;}

    public void setAuthorLink(String authorLink) {this.authorLink = authorLink;}
}
