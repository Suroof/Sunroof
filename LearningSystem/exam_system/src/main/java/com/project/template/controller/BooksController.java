package com.project.template.controller;

import com.project.template.common.Result;
import com.project.template.dto.BooksDTO;
import com.project.template.dto.ProductDTO;
import com.project.template.entity.Books;
import com.project.template.entity.Product;
import com.project.template.service.BooksService;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/books")
public class BooksController {
    @Autowired
    private BooksService booksService;

    @GetMapping("/bookslist")
    public Result<List<BooksDTO>> list() {
        List<Books> booksList = booksService.list();
        List<BooksDTO> booksDTOList = booksList.stream().map(books -> {
            BooksDTO booksDTO = new BooksDTO();
            BeanUtils.copyProperties(books, booksDTO );
            return booksDTO ;
        }).collect(Collectors.toList());
        return new Result<List<BooksDTO>>().success(booksDTOList);
    }
}
