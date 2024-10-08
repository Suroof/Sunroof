package com.project.template.dto;
//Data Transfer Object (DTO) for Product entity
public class ProductDTO {
    private Integer id;
    private String name;
    private String variety;
    private Double price;

    // Getters and Setters
    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {this.id = id;}

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getVariety() {
        return variety;
    }

    public void setVariety(String variety) {
        this.variety = variety;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }
}
