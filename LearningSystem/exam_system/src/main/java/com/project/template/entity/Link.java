package com.project.template.entity;

import com.project.template.entity.BaseEntity;
import lombok.Getter;
import lombok.Setter;


@Getter
@Setter
public class Link extends BaseEntity {

    private String name;

    private String link;
}