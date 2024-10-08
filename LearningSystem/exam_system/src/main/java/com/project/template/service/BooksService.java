package com.project.template.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.project.template.dto.BooksDTO;
import com.project.template.entity.Books;

public interface BooksService extends IService<Books> {
    /**
     * 根据id查询书籍
     * @param id
     * @return
     */
    BooksDTO getBooksById(Integer id);


    void addBooks(BooksDTO booksDTO);

    void updateBooks(BooksDTO booksDTO);


    void deleteBooks(Integer id);
}
